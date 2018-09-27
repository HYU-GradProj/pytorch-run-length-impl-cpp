#include <iostream>
#include <bitset>
#include <cstring>

template <typename T>
int compress(T* a, int len)
{
  T assign_arr[len] = {0, };
  T* assign_pointer = assign_arr;
  T* num_check_pointer = a;

  for(;;)
  {
    int num_cnt = 1;
    T checked_num = *num_check_pointer;
    
    // find count of checked_num
    num_check_pointer++;
    while(checked_num == *num_check_pointer)
    {
      if (int(num_check_pointer - a) >= len)
        break;
        
      num_cnt++;
      num_check_pointer++;
    } 
    
    // first, put count of checked_num 
    *assign_pointer = *reinterpret_cast<T*>(&num_cnt);
    assign_pointer++;
    // second, put checked_num
    *assign_pointer = checked_num;
    assign_pointer++;

    printf("num_cnt : %d, checked_num : %f\n", num_cnt, checked_num);
    printf("%d\n", int(assign_pointer - assign_arr));
    bool is_finished = int(num_check_pointer - a) == len;
    if (is_finished)
    {
      memcpy(a, assign_arr, sizeof(T) * len);
      break;
    }
  }

  int compressed_len = int(assign_pointer - assign_arr) + 1;
  for (int i = 0; i < compressed_len; i++)
    a[i + 1] = a[i];
  a[0] = compressed_len;
  
  return compressed_len;
}

template <typename T>
void decompress(T* a, int len)
{
  T original_arr[len] = { 0, };
  int original_idx = 0;

  for (T* pointer = a + 1; int(pointer - a) < a[0]; pointer += 2)
  {
    int num_count = *reinterpret_cast<int*>(pointer);
    T num = *(pointer + 1);

    if (num_count == 0)
        break;

    if (num != 0)
    {
      for (int i = 0; i < num_count; i++)
        original_arr[original_idx + i] = num;
      original_idx += 1;
    }
    else
      original_idx += num_count;
  }

  memcpy(a, original_arr, sizeof(T) * len);
}
