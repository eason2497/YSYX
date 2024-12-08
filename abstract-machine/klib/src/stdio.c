#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

static void reverse(char *s, int len) {   //reverse String
  for (int j = 0, k = len - 1; j < k; j++, k--) {
    char temp = s[j];
    s[j] = s[k];
    s[k] = temp;
    }
}

static int itoa(int n, char *s, int base) {  //int to String
  assert(base <= 16);

  int i = 0;
  int sign = n;
  int bit;
  if (sign < 0)
    n = -n;
  do {
    bit = n % base;
    if (bit >= 10) {
      s[i++] = 'a' + bit - 10;
    } else { 
      s[i++] = '0' + bit;
    }
  } while ((n /= base) > 0);
  if (sign < 0) {
    s[i++] = '-';
  }
  reverse(s, i);
  return i;
}

int printf(const char *fmt, ...) {
  panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {   //实现了hit good trip但是总觉得哪里不对，之后继续测试
  va_list ap;
  int d;
  char *str = out;
  char *s;

  va_start(ap, fmt);
  for (;*fmt != '\0'; ++fmt) {
    if (*fmt != '%') {
      *out = *fmt;
      ++out;
    } else {
      switch (*(++fmt)) {
        case '%':
          *out = *fmt;
          ++out;
          break;
        case 's':
          s = va_arg(ap, char *);     //va_arg(va_list ap, type)检索参数列表中类型为type的下一个参数
          strcat(out, s);
          out += strlen(out);
          break;
        case 'd':
          d = va_arg(ap, int);
          out += itoa(d, out, 10);
          break;
        }
    }
  }
  *out = '\0';
  va_end(ap);
  return out - str;
  //panic("Not implemented");
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
