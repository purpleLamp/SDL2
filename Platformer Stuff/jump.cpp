void jump() 
{
    //keep track of delta time variable
    delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f; //time since last frame converted to seconds
    last_frame_time = SDL_GetTicks(); //milliseconds since window init

    if (player.jumpPressed && player.isGrounded && canJump)
    {
        jumpTimer = 0; 
        jumpRequest = true;
        canJump = false;
    }
    if (jumpRequest)
    {
        dy -= jumpPw;
        jumpTimer += delta_time;
    }
    if (!player.jumpPressed || jumpTimer > jumpDur)
    {
        jumpRequest = false;
    }

    dy += gravity;
    player.y += dy * delta_time;    
}
