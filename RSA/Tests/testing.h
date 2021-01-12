#include "../src/RSA.h"

template<typename InputIterator1, typename InputIterator2>
bool range_equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2);
bool compare_files(const std::string& filename1, const std::string& filename2);
std::string gen_random(const int len);
int testing(int max_iter);

