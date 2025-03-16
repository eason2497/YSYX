#include <am.h>
#include <nemu.h>
#include <sys/time.h>

static uint64_t boot_time = 0;

///*
static uint64_t read_time() {
  uint64_t us_high = inl(RTC_ADDR + 4);         //访问RTC_ADDR + 4时，才会更新时间 
  uint64_t us_low = inl(RTC_ADDR);              //之前dhrystone浮点数错误是因为更新问题导致除零了
  uint64_t time = ((uint64_t)us_high << 32) | us_low;
  return time;
}
//*/

void __am_timer_init() {                                    //这种做法是否会导致报错存疑
  boot_time = read_time();
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  //uint64_t current = read_time();
  uptime->us = read_time() - boot_time;
  //boot_time = current;
  //uint64_t us_low = inl(RTC_ADDR);
  //uint64_t us_high = inl(RTC_ADDR + 4);
  //uptime->us = ((uint64_t)us_high << 32) | us_low;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
