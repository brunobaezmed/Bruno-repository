package com.S1.Sone.models;

import java.io.Serializable;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;

import interfaces.Utime;

@Entity
public class Userstime implements Utime,Serializable{
	

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	@Id
	private long Id;
	@Column
	private int age;

	public long getId() {
		
		return this.Id;
	}
	
	public int getAge() {
		
		return age;
	}

	public void setAge(int age) {
		this.age=age;		
	}
		
}

	