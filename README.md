# CanSat 2027, Flight Software ;-;

Flight software for the UF SSDC CanSat 2027 entry, a PocketQube deployment mission.

- **Mission:** the container releases a 2P PocketQube satellite at 90 percent of peak altitude
- **Radio:** ESPNOW, required by X1. XBee is an optional backup
- **Telemetry:** 4 Hz on both vehicles
- **Launch:** 12 June 2027. PDR documents due 28 January 2027

| Environment | What it is |
|---|---|
| `native` | Runs on your laptop. Unit tests. **No hardware needed** |
| `container` | The container flight computer. Not enabled yet |
| `pocketqube` | The PocketQube flight computer. Not enabled yet |

---

## Setup

Install these in order.

**1. Python 3** from [python.org](https://www.python.org/downloads/).
Tick **Add Python to PATH** during install.

**2. Git** from [git-scm.com](https://git-scm.com/download/win). Accept the defaults.

**3. VS Code** from [code.visualstudio.com](https://code.visualstudio.com).

**4. PlatformIO IDE.** In VS Code press `Ctrl+Shift+X`, search **PlatformIO IDE**, install.
First install takes several minutes, watch the bottom status bar. Reload when asked.

**5. Add PlatformIO to your PATH.**

1. Press the **Windows key**, type `environment variables`, open *Edit the system environment variables*
2. Click **Environment Variables**
3. Under **User variables**, select `Path`, click **Edit**
4. Click **New**, paste: `%USERPROFILE%\.platformio\penv\Scripts`
5. Click **OK** on all three dialogs
6. **Close and reopen your terminal.** If you use VS Code's terminal, close and reopen VS Code entirely. PATH changes do not apply to windows that were already open

Verify, all three should print a version:
```
python --version
git --version
pio --version
```

---

## Get the code and run the tests

```
git clone https://github.com/UF-SSDC-CanSat/Flight-Software
cd Flight-Software
pio test -e native
```

In VS Code use **File → Open Folder** and pick the folder containing `platformio.ini`.

You should see `[PASSED]` and a summary saying it succeeded. That is it, you are set up.

---

## Troubleshooting

**`'pio' is not recognized`**
PATH is not set, or your terminal was open before you set it. Close it and open a new one.
If VS Code, restart VS Code. Otherwise use PlatformIO's terminal: alien icon → Quick
Access → Miscellaneous → New Terminal.

**PlatformIO does nothing when you open the folder**
Wrong folder. Open the one containing `platformio.ini`, not a parent or a subfolder.

**`Error: Nothing to build`**
A folder under `test/` has no source file in it. Every test suite folder needs at least
one `.c` file. Empty folders always error.

**Compiler or `gcc` not found**
You need a host C compiler. Download [w64devkit](https://github.com/skeeto/w64devkit/releases),
extract it somewhere permanent, and add its `bin` folder to PATH the same way as step 5.

**Tests cannot find the fixture CSV**
Run `pio test` from the project root, the folder with `platformio.ini` in it.

---

## Repo layout

```
lib/hal/          interface headers only, what drivers need from the platform
lib/hal_fake/     fake implementation, lets drivers run in tests
lib/core/         state machine, telemetry, commands, persistence
lib/gnc/          attitude estimation and camera pointing control
lib/drv_*/        one folder per sensor driver
src/              per target entry points, wiring only, no logic
test/             one folder per test suite, each needs a source file
test/fixtures/    data files only, the 2026 flight logs
tools/            Python analysis scripts
docs/             requirements, interfaces, decision records
docs/adr/         architecture decision records
```

### The rule that matters most

`lib/core` and `lib/gnc` include only standard C headers. No Arduino, no ESP-IDF,
no vendor libraries. Everything they need arrives as a function argument.

That is what lets them run in the `native` environment, and it is the main structural
difference from the 2026 codebase, where the barometer driver included the GNC header
and nothing could be tested without hardware.

---

## Test fixtures

`test/fixtures/` holds the real 2026 competition flight logs.

- `LOGFILE_OFFICIAL.csv`, what the ground station received, 764 packets
- `LOG26.CSV`, the onboard SD card, three sessions, the last one is the flight

**The rocket launches at packet 759.** Any flight state machine we write must transition
out of `LAUNCH_PAD` on that data, and must not transition before it.

The 2026 software failed both. It reported `LAUNCH_PAD` for all 765 packets, including
six seconds of powered ascent at up to 150 m/s.

---

## Contributing

```
git switch dev
git pull
git switch -c feature/short-name
# work, commit
git push -u origin feature/short-name
```

Then open a pull request into `dev` on GitHub.

1. CI must be green
2. One approval
3. Say which requirement your change serves, for example CTR19, F2, PQ29
4. Branches are named for the change, not for the person
5. Nothing lives longer than two weeks
