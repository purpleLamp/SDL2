/**
Simple main game loop function that does 3 things 
while every frame: process input, update everything, render objects
**/

int main(int argc, char* args[])
{
    game_is_running = init();

    awake();
    
    while (game_is_running)
    {
        process_input();
        update();
        render();
    }

    destroy_window();

	return 0;
}
