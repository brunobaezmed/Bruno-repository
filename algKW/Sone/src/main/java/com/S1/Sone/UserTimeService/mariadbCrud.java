package com.S1.Sone.UserTimeService;


import org.springframework.data.repository.CrudRepository;
import javax.management.Query;
import com.S1.Sone.models.Userstime;
public interface MariadbCrud extends CrudRepository<Userstime,Long>  {
	@Query("SELECT usersaccess.name  usersaccess.Lastname , userstime.age FROM usersaccess,userstime WHERE usersaccess.id = userstime.id");
}
