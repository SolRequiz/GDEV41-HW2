#include <raylib.h>
#include <raymath.h> /*just in case*/

float FPS = 40;

int main(){
    InitWindow(800, 600, "Pew Pew Pew");

    struct Circle{
        float x;
        float y;
        float radius;
        Color color;
    };

    Circle player;
    player.x = 250;
    player.y = 250;
    player.radius = 75;
    player.color = GRAY;

    Circle bullet;
    /*I would assume the bullet has to initialize at the same position as the player since that's its origin point*/
    bullet.x = player.x;
    bullet.y = player.y;
    bullet.radius = 10;
    bullet.color = BLUE;

    while(!WindowShouldClose){
        /*feel free to change values once we add fps*/
        if(IsKeyDown(KEY_W)){
            player.y -= 10;
        }
        if(IsKeyDown(KEY_A)){
            player.x -= 10;
        }
        if(IsKeyDown(KEY_S)){
            player.y += 10;
        }
        if(IsKeyDown(KEY_D)){
            player.x += 10;
        }

        BeginDrawing();
        ClearBackground(WHITE);
        DrawCircle(player.x, player.y, player.radius, player.color);
        /*the bullet is there i just didn't draw it yet*/
        EndDrawing();
    }

    CloseWindow();
    return 0;
}