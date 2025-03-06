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
    n /= base;
  } while (n);
  if (sign < 0) {
    s[i++] = '-';
  }
  reverse(s, i);
  return i;
}

void puts(const char* str){
  while (*str) {
    putch(*str++);
  }
}
/*
int printf(const char *fmt, ...) {
  char buffer[1024];
  va_list ap;
  int temp = 0;
  const char *str = NULL;
  char *str_buffer = buffer;
  char *s = NULL;

  int counter = 0;
  int number = 0;
  int decimal = 0;


  va_start(ap, fmt);
  for (counter = 0, str = fmt; *(str) != '\0';) {
      switch (*str) {
        case '%':
          str++;
          switch(*str) {
            case 'd':
              temp = va_arg(ap, int);
              decimal = temp;

              while (decimal) {
                number++;
                counter++;
                decimal /= 10;
              }

              decimal = temp;

              while (number) {
                *(str_buffer + number - 1) = (decimal % 10);
                decimal /= 10;
                number--;
              }
              str_buffer += number;
              break;
            case 'c':
              temp = va_arg(ap, int);
              *(str_buffer++) = temp;
              break;
            case 's':
              s = va_arg(ap, char*);
              while (s != NULL) {
                *(str_buffer++) = *(s++);
                counter++;
              }
              break;
            default:
              break;
          }
        default:
          *(str_buffer++) = *(str++);
          counter++;
      }
  }
  va_end(ap);
  str_buffer = NULL;
  for(int i = 0; buffer[i] != '\0'; i++) {
    putch(buffer[i]);
  }
  return counter;
  //panic("Not implemented");
}
*/

void zerofills(int size, char* str) {
  int i = 0;
  while (size > 0) {
    str[i++] = '0';
    size--;
  }
}


int vsprintf(char *out, const char *fmt, va_list ap) {
  int d;
  char *str = out;
  char *s;
  int zerofill = 0;

  while (*fmt != '\0') {
    if (*fmt != '%') {
      *str++ = *fmt++;
    } else {
      ///*
      if (*(++fmt) == '0') {
        fmt++;
        zerofill = 0;
        while (1) {
          char c = (char)(*fmt);     //这里试一下char 转 int
          int diff = c - '0';
          if (diff > 9) {
            break;
          }
          fmt++;
          zerofill = zerofill * 10 + diff;
        }
        //fmt++;
      }
      //*/
      switch (*(fmt)) {
        case 'c':
          char ch = va_arg(ap, int);
          *str++ = ch;
          break;
        case 's':
          s = va_arg(ap, char *);     //va_arg(va_list ap, type)检索参数列表中类型为type的下一个参数
          strcpy(str, s);
          str += strlen(s);
          break;
        case 'd':
          d = va_arg(ap, int);
          if (zerofill != 0) {
            //puts("zerofilled");
            zerofills(zerofill, str);
            itoa(d, str, 10);
            str += zerofill;
            //str += itoa(d, str, 10);
          } else {
            str += itoa(d, str, 10);
          }
          break;
        default:
          break;
        }
        fmt++;
    }
  }
  *str++ = '\0';
  return str - out;
  //panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {   //实现了hit good trip但是总觉得哪里不对，之后继续测试
  va_list ap;
  va_start(ap, fmt);
  int ret = vsprintf(out, fmt, ap);
  va_end(ap);
  return ret;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

#define CHECK_AND_RETURN do { \
  if (written>=n) { \
    return written; \
  } \
} while(0)
int vsnprintf(char *out, size_t n, const char *fmt, va_list args) {
  int written = 0;
  const char* p = fmt;
  while (*p!='\0') {
    if (*p=='%' && (*(p+1)=='s' || *(p+1)=='d')) {
      p++;
      if (*p=='s') {
        const char *str = va_arg(args, const char *);
        while (*str) {
            *out++ = *str++;
            written++;
            CHECK_AND_RETURN;
        }
      } else {
        assert(*p=='d');
        int v = va_arg(args, int);
        if (v==0) {
          *out++ = '0';
          written++;
          CHECK_AND_RETURN;
        } else {
          if (v<0) {
            *out++ = '-';
            written++;
            CHECK_AND_RETURN;
            v = -v;
          }
          char *i_buf=out;
          int len=0;
          while(v>0) {
            len++;
            *out++ = '0' + v % 10;
            v /= 10;
            written++;
            CHECK_AND_RETURN;
          }
          for(int i=0; i<len/2; i++) {
            char t=i_buf[len-i-1];
            i_buf[len-i-1]=i_buf[i];
            i_buf[i]=t;
          }
        }
      }
    } else {
      *out++ = *p;
      written++;
      CHECK_AND_RETURN;
    }
    p++;
  }
  *out='\0';
  return written;
}
static char buffer[1024];
int printf(const char *fmt, ...) {
  ///*
  va_list ap;
  va_start(ap, fmt);
  int ret = vsprintf(buffer, fmt, ap);
  //int ret = vsnprintf(buffer, 1024, fmt, ap);
  va_end(ap);
  for(int i = 0; i < ret; i++) {
    putch(buffer[i]);
  }
  return ret;
  //*/
  //panic("Not implemented");
}

#endif
