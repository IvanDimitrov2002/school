package com.example.demo;

import java.util.ArrayList;
import java.util.Arrays;

import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.stereotype.Service;

@Service
public class JwtUserDetailsService implements UserDetailsService {
    @Override
    public UserDetails loadUserByUsername(String username) throws UsernameNotFoundException {
        GrantedAuthority deskRole = new SimpleGrantedAuthority("DESK");
        GrantedAuthority enrollRole = new SimpleGrantedAuthority("ENROLL");

        if ("user".equals(username)) {
            return new User("user", "$2a$10$n2xX.qUbxgHvHVZoHputzewLNhEaEqod.Q0ixYaeNI4s/f8IcwvmW",
                    Arrays.asList(enrollRole));
        } else if ("user1".equals(username)) {
            return new User("user1", "$2a$10$puqUxIYnhd/UxD7HcACwu.L3RF6Ef1mAhZQIOWB0Y3H6jPhuz6yQS",
                    Arrays.asList(enrollRole));
        } else if ("desk".equals(username)) {
            return new User("desk", "$2a$10$11.huGMWyXoZoi4Rr3YnyODLj/JqBnwfORm4bOvHiqDjiGt9n21/2",
                    Arrays.asList(deskRole));
        } else if ("desk1".equals(username)) {
            return new User("desk1", "$2a$10$4DAMSq4gXTdDisyTuTa70u44EDLF4llQ3pDRS461tBj.yNZ7QFVMS",
                    Arrays.asList(deskRole));
        } else if ("admin".equals(username)) {
            return new User("admin", "$2a$10$BzIBdLaTr3nDCQAZTPp9AOf28RLRmuMGXKFIPjPlMMxWRcQVI5XKO",
                    Arrays.asList(deskRole, enrollRole));
        } else {
            throw new UsernameNotFoundException("User not found with username: " + username);
        }
    }
}
