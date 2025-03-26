#ifndef UNITTEST_H_
#define UNITTEST_H_

#define ASSERT(condition, name) unittest_assert(condition, name, __FILE__, __LINE__)

int unittest_assert(int condition, char *name, char *file, int line);
int test_main();

#endif