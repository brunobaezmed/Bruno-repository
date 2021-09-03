package com.S1.Sone;

import java.util.Date;
import java.util.GregorianCalendar;
import java.util.TimeZone;

import org.junit.jupiter.api.Test;
class SoneApplicationTests {
	
		@Test
		void NtestDataaccess() {	
	
	}
		@Test
		public static void main(String args[]) {
		GregorianCalendar calendar=new GregorianCalendar();
		int t=calendar.getFirstDayOfWeek();
		t=calendar.getWeekYear();
		t=calendar.getFirstDayOfWeek();
		Date Time=calendar.getTime();
		TimeZone timezone=calendar.getTimeZone();
			}

}