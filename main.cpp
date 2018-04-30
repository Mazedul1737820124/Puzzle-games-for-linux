#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
void Operation();
void PlayGame();
void Htp();
void About();
void Close();

char Ch;
char Ch1;

int Count = 0;

void PlayGame() {

    RenderWindow app(VideoMode(470, 470), "****PUZZLE****");
    app.setFramerateLimit(100);

    Texture m;


    m.loadFromFile("/home/mazedul/Education/Projects/Puzzle/update/images/logos.png");

    int Squaresize = 120;
    int PicArr[6][6] = {0};
    Sprite sprite[20];

    int count = 0;

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) {
            count++;
            sprite[count].setTexture(m);
            sprite[count].setTextureRect(IntRect( i* Squaresize,  j* Squaresize, Squaresize - 5, Squaresize - 5));
            PicArr[i + 1][j + 1] = count;
//           app.draw(sprite[count]);
//            app.display();

        }
    while (app.isOpen()) {

        Event p;

        while (app.pollEvent(p)) {
            if (p.type == Event::Closed)
                app.close();

            if (p.type == Event::MouseButtonPressed)
                if (p.key.code == Mouse::Left) {

                    Vector2i pos = Mouse::getPosition(app);
                    int x = pos.x / Squaresize +1;
                    int y = pos.y / Squaresize +1;

                    int dx = 0;
                    int dy = 0;

                    if (PicArr[x + 1][y] == 16) {
                        dx = 1;
                        dy = 0;
                    }

                    if (PicArr[x][y + 1] == 16) {
                        dx = 0;
                        dy = 1;
                    }
                    if (PicArr[x][y - 1] == 16) {

                        dx = 0;
                        dy = -1;
                    }

                    if (PicArr[x - 1][y] == 16) {
                        dx = -1;
                        dy = 0;
                    }

                    int n = PicArr[x][y];
                    PicArr[x][y] = 16;
                    PicArr[x + dx][y + dy] = n;  //Animation of Squares

                    sprite[16].move(-dx * Squaresize, -dy * Squaresize);
                    int Speed = 3;

                    for (int i = 0; i < Squaresize; i += Speed) {

                        sprite[n].move(Speed * dx, Speed * dy);
                        app.draw(sprite[16]);
                        app.draw(sprite[n]);
                        app.display();
                    }
                }

        }
        app.clear(Color::Transparent);

        for (int i=0;i<4;i++)
            for (int j = 0; j < 4; j++) {

                int n = PicArr[i + 1][j + 1];
                sprite[n].setPosition(i * Squaresize, j * Squaresize);
                app.draw(sprite[n]);

            }

        app.display();
    }

}

void Htp(){

    cout<<"\n\nThe 15-type sliding puzzle, because all of its pieces are squares"<<endl;
    cout<<"is one of the most straightforward to solve. If you need some help, "<<endl;
    cout<<"here are a few hints : "<<endl;

    cout<<"\n       <> Begin by maneuvering the 1 and 2 into their proper positions in the "<<endl;
    cout<<"          upper left corner."<<endl;
    cout<<"\n       <> Position the 3 in the upper right corner."<<endl;
    cout<<"\n       <> Maneuver the 4 under the 3."<<endl;
    cout<<"\n       <> Now slide the 3 to the left and the 4 up; the first row is done."<<endl;
    cout<<"\n       <> Repeat this process with next row, leaving row above intact."<<endl;
    cout<<"\n       <> Complete the puzzle by rearranging the pieces in the last two rows"<<endl;
    cout<<"          until they are in position."<<endl;
    cout<<"\n       <> Sometimes it's easier to create snakes of pieces in the proper order"<<endl;
    cout<<"          rather than put them in their final position individually."<<endl;
    cout<<"\n       <> If you're assembling a picture, study the design carefully before "<<endl;
    cout<<"          it's scrambled. It's harder to solve if you're not clear about the "<<endl;
    cout<<"          final outcome."<<endl;

}


void About(){

    cout<<"\n\nDeveloper  : Md. Mazedul Islam (Bangladeshi)" <<endl;
    cout<<"Designer   : Md. Mazedul Islam (Bangladeshi)"<<endl;
    cout<<"Contact    "<<endl;
    cout<<"Phone      : +8801770554970"<<endl;
    cout<<"Email      : mazedulislam4970@gmail.com"<<endl;
    cout<<"Github     : https://www.github.com/mazedul1737820124"<<endl;
    cout<<"Twitter    : https://www.twitter.com/mazedul70"<<endl;
    cout<<"Facebook   : https://www.facebook.com/mamazedulislam70"<<endl;
}



void Operation() {

    do {
        cout << "\n\n\n" << endl;

        cout << "*****************************************************" <<endl;
        cout << "*                                                   *" << endl;
        cout << "*            # Puzzle game #                        *" << endl;
        cout << "*                                                   *" << endl;
        cout << "*           Press 1 for play                        *" << endl;
        cout << "*           Press 2 for how to play                 *" << endl;
        cout << "*           Press 3 for exit                        *" << endl;
        cout << "*           Press 4 for about me                    *" << endl;
        cout << "*                                                   *" << endl;
        cout << "*                                                   *" << endl;
        cout << "*                                                   *" << endl;
        cout << "*                                                   *" << endl;
        cout << "*****************************************************"<<endl;
        X:
        cout << "\nPlease enter your choice  and : enter " << endl;

        cin >> Ch;

        switch (Ch) {                //Choice option

            case '1' :

                PlayGame();        //Call game
                //system("CLS");

                break;

            case '2' :

                Htp();//Game procedures
               // system("CLS");

                break;

            case '3' :
                system("CLS");
                Close();//Close program


            case '4' :

                About();            //About developers
                //system("CLS");

                break;

            default:
                ++Count;

                if (Count == 3) {

                    Close();
                }
                system("CLS");

                cout << " \nInvalid choice!!! : try again\n" << endl;
                goto X;

        }

        cout << "\n\nDo you want to continue : [Y/N] " << endl;
        cin >> Ch1;


        system("CLS");
    } while (Ch1 == 'Y' || Ch1 == 'y');

}

void Close(){

    cout<<"\n\n****************************************************"<<endl;
    cout<<"*                                                  *"<<endl;
    cout<<"*                                                  *"<<endl;
    cout<<"*                                                  *"<<endl;
    cout<<"*                                                  *"<<endl;
    cout<<"*                                                  *"<<endl;
    cout<<"*                                                  *"<<endl;
    cout<<"*                 Program exit                     *"<<endl;
    cout<<"*                                                  *"<<endl;
    cout<<"*                                                  *"<<endl;
    cout<<"*                                                  *"<<endl;
    cout<<"*                                                  *"<<endl;
    cout<<"*                                                  *"<<endl;
    cout<<"*                                                  *"<<endl;
    cout<<"****************************************************"<<endl;

    exit(1);
}

int main(){// main function

    Operation();

    return 0;

}


/*
  Name : Md. Mazedul Islam
  ID   : 1737820124
  Dept : CSE
  TMSS Engineering College
 */