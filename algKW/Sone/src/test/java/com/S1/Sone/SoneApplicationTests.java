package com.S1.Sone;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.orm.jpa.DataJpaTest;

import com.S1.Sone.UserTimeService.mariadbCrud;

class SoneApplicationTests {

		@Test
		void NtestDataaccess() {	
	
	}
		
}

/*

SELECT usersaccess.name , usersaccess.Lastname , userstime.age
FROM usersaccess,userstime
WHERE usersaccess.id = userstime.id;
*/