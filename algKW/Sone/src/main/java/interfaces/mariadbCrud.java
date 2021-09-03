package interfaces;


import org.springframework.data.repository.CrudRepository;

import com.S1.Sone.models.Users;
public interface mariadbCrud extends CrudRepository<Users,Long>  {

}
