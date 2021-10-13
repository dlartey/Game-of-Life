#include "unity.h"
#include "checker.h"
#include "grid.h"

void setUp(){

}
void tearDown(){

}

void test_checkAbove(){
    gridsize = 5;
    grid[2][2] = '1';
    grid[1][2] = '1';
    int x = checkAbove(2,2);
    TEST_ASSERT_EQUAL_INT(1,x);
}

void test_checkLeft(){
    gridsize = 5;
    grid[2][2] = '1';
    grid[2][1] = '1';
    int x = checkLeft(2,2);
    TEST_ASSERT_EQUAL_INT(1,x);
}

void test_checkRight(){
    gridsize = 5;
    grid[2][2] = '1';
    grid[2][3] = '1';
    int x = checkRight(2,2);
    TEST_ASSERT_EQUAL_INT(1,x);
}

void test_checkBelow(){
    gridsize = 5;
    grid[2][2] = '1';
    grid[1][2] = '1';
    int x = checkBelow(1,2);
    TEST_ASSERT_EQUAL_INT(1,x);
}

void test_topRight(){
    gridsize = 5;
    grid[1][3] = '1';
    grid[2][2] = '1';
    int x = checkUpperRight(2,2);
    TEST_ASSERT_EQUAL_INT(1,x);
}

void test_topLeft(){
    gridsize = 5;
    grid[2][2] = '1';
    grid[1][1] = '1';
    int x = checkUpperLeft(2,2);
    TEST_ASSERT_EQUAL_INT(1,x);
}

void test_bottomRight(){
    gridsize = 5;
    grid[2][2] = '1';
    grid[3][3] = '1';
    int x = checkLowerRight(2,2);
    TEST_ASSERT_EQUAL_INT(1,x);
}

void test_checkBottomLeft(){
    gridsize = 5;
    grid[2][2] = '1';
    grid[3][1] = '1';
    int x = checkLowerLeft(2,2);
    TEST_ASSERT_EQUAL_INT(1,x);
}
int main(){
    UNITY_BEGIN();
    RUN_TEST(test_checkAbove);
    RUN_TEST(test_checkBelow);
    RUN_TEST(test_checkLeft);
    RUN_TEST(test_checkRight);

    RUN_TEST(test_topRight);
    RUN_TEST(test_topLeft);
    RUN_TEST(test_checkBottomLeft);
    RUN_TEST(test_bottomRight);

    return UNITY_END();
}