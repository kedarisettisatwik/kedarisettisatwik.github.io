import './App.css' ;
import './Main.css' ;

import React from 'react';

function Main(){
    return(
        <section className='main'>
            <nav className='flex nav'>
                <div className='box1 flex'>
                    <h1>Aoight</h1>
                    <ul className='flex'>
                        <li>Home</li>
                        <li>Features</li>
                        <li>Contact</li>
                    </ul>
                </div>
                <div className='box2 flex'>
                    <li>Log In</li>
                    <li>Sign up</li>
                </div>
            </nav>
        </section>
    );
}

export default Main;