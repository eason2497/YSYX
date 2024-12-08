#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  const char *str;
  for (str = s; *str; ++str);
  return (str - s);
  //panic("Not implemented");
}

char *strcpy(char *dst, const char *src) {
  size_t i = 0;
  while (src[i] != '\0') {
    dst[i] = src[i];
    i++;
  }
  dst[i] = '\0';
  return dst;
  //panic("Not implemented");
}

char *strncpy(char *dst, const char *src, size_t n) {
  size_t i;
  for (i = 0;i < n && src[i] != '\0'; i++){
    dst[i] = src[i];
  }
  for(;i < n; i++) {
    dst[i] = '\0';
  }
  return dst;
  //panic("Not implemented");
}

char *strcat(char *dst, const char *src) {
  size_t dst_len = strlen(dst);
  size_t i = 0;
  while (src[i] != '\0') {
    dst[dst_len + i] = src[i];
    i++;
  }
  dst[dst_len + i] = '\0';
  return dst;
  //panic("Not implemented");
}

int strcmp(const char *s1, const char *s2) {
  size_t i;
  for (i = 0;i < strlen(s1);i++) {
    if (s1[i] < s2[i]) {
      return -1;
    } else if (s1[i] > s2[i]) {
      return 1;
    }
  }
  if (s2[i] != '\0') {
    return -1;
  }
  return 0;
  //panic("Not implemented");
}

int strncmp(const char *s1, const char *s2, size_t n) {
  size_t i;
  for (i = 0;i < n && i < strlen(s1);i++) {
    if (s1[i] < s2[i]) {
      return -1;
    } else if (s1[i] > s2[i]) {
      return 1;
    }
  }
  return 0;
  //panic("Not implemented");
}

void *memset(void *s, int c, size_t n) {
  size_t i;
  char *ptr = s;
  for (i = 0;i < n;i++) {
    ptr[i] = c;
  }
  return s;
  //panic("Not implemented");
}

void *memmove(void *dst, const void *src, size_t n) {
  
  //size_t i;
  char *ptr_dst = (char *)dst;
  char *ptr_src = (char *)src;

  if (dst <= src) {               
    while(n--) {
      *ptr_dst++ = *ptr_src++;
    }
  } else if (dst > src) {         //当dst的位置后于src是，可以倒着赋值，这样就不会造成数据损失
    ptr_dst += n - 1;
    ptr_src += n - 1;
    while(n--) {
      *ptr_dst-- = *ptr_src--;
    }
  }
  return dst;
  //panic("Not implemented");
}

void *memcpy(void *out, const void *in, size_t n) {
  size_t i;
  char *ptr_out = (char *)out;
  char *ptr_in = (char *)in;

  for (i = 0;i < n;i++) {
    ptr_out[i] = ptr_in[i];
  }
  return out;
  //panic("Not implemented");
}

int memcmp(const void *s1, const void *s2, size_t n) {
  size_t i;
  char * str1 = (char *) s1;
  char * str2 = (char *) s2;
  
  for (i = 0; i < n;i++) {
    if (str1[i] < str2[i]) {
      return -1;
    } else if (str1[i] > str2[i]) {
      return 1;
    }
  }
  return 0;
  //panic("Not implemented");
}

#endif
