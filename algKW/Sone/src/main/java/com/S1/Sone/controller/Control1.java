package com.S1.Sone.controller;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import  org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import com.S1.Sone.UserService.UserService;
import com.S1.Sone.models.Users;
import com.S1.Sone.models.Userstime;

@RestController
public class Control1 {
	
	@Autowired
	private UserService personservice;
	
    @GetMapping(value="users/user/{id}")
    	private Users user(@PathVariable("id") long id) {
    		return personservice.getById(id);
    	}
    @GetMapping(value="users")
    	private List<Users> all() {
    		return personservice.getAll();
    			}
	@DeleteMapping(value="user/delete/{id}")
		private void del(@PathVariable("id") long id) {
	
		personservice.delete(id);
				}
   
	@PostMapping(value="user/post")
		private	long ins_userID(@RequestBody Users user) {
					
				personservice.save_update(user);
				return user.getId();
			}
	
	@PostMapping(value="users/post")
		private void ins_usersID(@RequestBody List<Users> users ) {
				personservice.save_update(users);
				
			}
	@PostMapping(value="userstime/post")
		private long ins_userTime(@RequestBody Userstime utime) {
			personservice.save_update(utime);
			return utime.getId();
	}
	@GetMapping(value="usertime/{id}")
	private Userstime ins_userTime(@PathVariable long id) {
		
		return personservice.getbyId(id);
}

}
