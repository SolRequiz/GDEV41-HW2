#include <raylib.h>
/*just in case*/    

int FPS = 30;
typedef struct Timer {
    double startTime;   // Start time (seconds)
    double lifeTime;    // Lifetime (seconds)
} Timer;

void StartTimer(Timer *timer, double lifetime)
{
    timer->startTime = GetTime();
    timer->lifeTime = lifetime;
}

bool UpdateTimer(Timer timer)
{
    return GetTime() - timer.startTime >= timer.lifeTime;
}

double TimerDone(Timer timer)
{
    return GetTime() - timer.startTime;
}

//g++ pewpewpewpew.cpp -o out -I src/ -L raylib/ -lraylib -lopengl32 -lgdi32 -lwinmm
int main(){
    
    InitWindow(800, 600, "Pew Pew Pew");
    SetTargetFPS(FPS);


    struct Circle{
        float x;
        float y;
        float radius;
        Color color;
        float speed;
        int direction; //1 up, 2 left, 3 down, 4 right
        bool isShot;
        Timer shield;
        float shield_life;
    };
    Circle shield;
    shield.shield ={ 0 };
    shield.shield_life = 1.0f;

    Circle player;
    player.x = 250;
    player.y = 250;
    player.radius = 75;
    player.color = GRAY;
     player.speed = 10;
     player.direction=0;//1 up, 2 left, 3 down, 4 right, 5 down right, 6 down left, 7 up right, 8 up left
    player.isShot=false;

    Circle bullet;
    /*I would assume the bullet has to initialize at the same position as the player since that's its origin point*/
    bullet.x = player.x;
    bullet.y = player.y;
    bullet.radius = 10;
    bullet.color = BLUE;
    bullet.speed =20;
    bullet.direction=0;
    bullet.isShot = false;

    while(!WindowShouldClose()){
        /*feel free to change values once we add fps*/
        if(IsKeyDown(KEY_W)){
            player.y -= player.speed;
            if(bullet.isShot==false){
            bullet.direction=1;}

        }
        if(IsKeyDown(KEY_A)){
            player.x -= player.speed;
            if(bullet.isShot==false){
            bullet.direction=2;}
        }
        if(IsKeyDown(KEY_S)){
            player.y += player.speed;
            if(bullet.isShot==false){
            bullet.direction=3;}

        }
        if(IsKeyDown(KEY_D)){
            player.x += player.speed;
            if(bullet.isShot==false){
                 bullet.direction=4;
            }
        }
        //double keypressed
        if(IsKeyDown(KEY_D) && IsKeyDown(KEY_S)){
            player.y += player.speed/2;
            player.x += player.speed/2;
            if(bullet.isShot==false){
                 bullet.direction=5;
            }
        }
        if(IsKeyDown(KEY_A) && IsKeyDown(KEY_S)){
            player.y += player.speed/2;
            player.x -= player.speed/2;
            if(bullet.isShot==false){
                 bullet.direction=6;
            }
        }
        if(IsKeyDown(KEY_D) && IsKeyDown(KEY_W)){
            player.y -= player.speed/2;
            player.x += player.speed/2;
            if(bullet.isShot==false){
                 bullet.direction=7;
            }
        }
        if(IsKeyDown(KEY_A) && IsKeyDown(KEY_W)){
            player.y -= player.speed/2;
            player.x -= player.speed/2;
            if(bullet.isShot==false){
                 bullet.direction=8;
            }
        }
        if(IsKeyPressed(KEY_SPACE)){
            StartTimer(&shield.shield,shield.shield_life);
        }
        UpdateTimer(&shield.shield);

        if(!TimerDone(&shield.shield)){

        }
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            bullet.isShot=true;

            }
            if(bullet.isShot==true){
                bullet.color=BLUE;
                if(bullet.direction==8){
                        if(bullet.x>=0){
                        bullet.x -= bullet.speed;
                        bullet.y -= bullet.speed;
                        bullet.direction=8;
                    }
                    else{
                     bullet.isShot=false;
                }
                }
                if(bullet.direction==7){
                        if(bullet.x<=GetScreenWidth()){
                        bullet.x += bullet.speed;
                        bullet.y -= bullet.speed;
                        bullet.direction=7;
                    }
                    else{
                     bullet.isShot=false;
                }
                }
                if(bullet.direction==6){
                        if(bullet.x>=0){
                        bullet.x -= bullet.speed;
                        bullet.y += bullet.speed;
                        bullet.direction=6;
                    }
                    else{
                     bullet.isShot=false;
                }
                }
                if(bullet.direction==5){
                        if(bullet.x<=GetScreenWidth()){
                        bullet.x += bullet.speed;
                        bullet.y += bullet.speed;
                        bullet.direction=5;
                    }
                    else{
                     bullet.isShot=false;
                }
                }

                 if(bullet.direction==4){
                        if(bullet.x<=GetScreenWidth()){
                        bullet.x += bullet.speed;
                        bullet.direction=4;
                    }
                    else{
                     bullet.isShot=false;
                }

                }
                else if(bullet.direction==3){
                    if(bullet.y<=GetScreenHeight()){
                        bullet.y += bullet.speed;
                        bullet.direction=3;
                    }
                    else{
                     bullet.isShot=false;
                }
                }
                
                else if(bullet.direction==2 ){
                    if(bullet.x>=0){
                        bullet.x -= bullet.speed;
                        bullet.direction=2;
                    }
                    else{
                     bullet.isShot=false;
                }
                }
                
                else if(bullet.direction==1 ){
                    if(bullet.y>=0){
                    bullet.y -= bullet.speed;
                    bullet.direction=1;
                    }
                    else{
                     bullet.isShot=false;
                }
                }
            }
            else{
                bullet.y=player.y;
                bullet.x=player.x;
                bullet.color=player.color;
            }
           
        
        BeginDrawing();
        ClearBackground(WHITE);
        

        DrawCircle(player.x, player.y, player.radius, player.color);
        DrawCircle(bullet.x,bullet.y,bullet.radius,bullet.color);

        /*the bullet is there i just didn't draw it yet*/
        EndDrawing();
    }

    CloseWindow();
    return 0;
}