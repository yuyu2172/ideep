#include <iostream>
#include <ideep/lru_cache.hpp>

using namespace ideep;
using namespace ideep::utils;

void test_lru() {
  lru_cache<int, int> base(3);
  base.insert(std::make_pair(6, 33));
  base.insert(std::make_pair(6, 33));
  base.insert(std::make_pair(6, 33));
  base.insert(std::make_pair(128, 28));

  int test_list[] = {128, 32, 6, 3};

  for (unsigned i = 0; i < sizeof(test_list)/sizeof(int); ++i) {
    printf("find %d\n", test_list[i]);
    auto it = base.find(test_list[i]);
    if (it != base.end())
      printf("value: %d\n", it->second);
    else
      printf("Nothing\n");
  }

  base.insert(std::make_pair(20, 111));
  auto tbd = base.find(20);
  auto handle = base.erase(tbd);
  printf("Delete after %d\n", handle->second);

  printf("After insert (%d, %d)\n", 20, 111);
  for (unsigned i = 0; i < sizeof(test_list)/sizeof(int); ++i) {
    printf("find %d\n", test_list[i]);
    auto it = base.find(test_list[i]);
    if (it != base.end())
      printf("value: %d\n", it->second);
    else
      printf("Nothing\n");
  }
}

void test_to_string() {
  tensor::dims A{ 2, 22, 24, 25 };
  tensor::dims B{ 8, 2, 12, 58 };
  tensor::dims C{ 32, 2, 3, 44 };
  int a=0, b = 32, c = 2, d = 44;

  std::cout<<to_string(A, B, C)<<std::endl;
  std::cout<<to_string(A, a, B, b, C, c, d)<<std::endl;
}

void test_cache() {
}

int main() {
  test_lru();
  test_to_string();
}
