void movement() 
{
    //keep track of delta time variable
    delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f; //time since last frame converted to seconds
    last_frame_time = SDL_GetTicks(); //milliseconds since window init

    //handle x movement
    dx += ((player.rightPressed * runPw) - (player.leftPressed * runPw));
    //apply x movement
    player.x += dx * delta_time;

    //handle y movement
    dy += gravity;
    //apply y movement
    player.y += dy * delta_time;    
}
