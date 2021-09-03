---
layout: post
title: "[Java] Java Utils"
date: 2021-09-03 11:13:00 +0900
category: java
---

- Calendar
	```java
	import java.util.Calendar;

	public class Test {
		public static void main(String[] args) {

			Calendar calendar = Calendar.getInstance();
			System.out.println(calendar);
		}
	}
	```
	```plain text
	java.util.GregorianCalendar[time=1630638143978,areFieldsSet=true,areAllFieldsSet=true,lenient=true,zone=sun.util.calendar.ZoneInfo[id="Asia/Seoul",offset=32400000,dstSavings=0,useDaylight=false,transitions=30,lastRule=null],firstDayOfWeek=1,minimalDaysInFirstWeek=1,ERA=1,YEAR=2021,MONTH=8,WEEK_OF_YEAR=36,WEEK_OF_MONTH=1,DAY_OF_MONTH=3,DAY_OF_YEAR=246,DAY_OF_WEEK=6,DAY_OF_WEEK_IN_MONTH=1,AM_PM=1,HOUR=0,HOUR_OF_DAY=12,MINUTE=2,SECOND=23,MILLISECOND=978,ZONE_OFFSET=32400000,DST_OFFSET=0]
	```
