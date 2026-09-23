#include <unity.h>

void setUp(void)    { }
void tearDown(void) { }

void test_harness_works(void)
{
    TEST_ASSERT_EQUAL_INT(4, 2 + 2);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_harness_works);
    return UNITY_END();
}