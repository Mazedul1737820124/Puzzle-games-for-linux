#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

int main() {


    RenderWindow app(VideoMode(470, 470), "****PicArr****");
    app.setFramerateLimit(100);

    Texture m;
    m.loadFromFile("/home/mazedul/Education/Projects/PicArr/images/logos.png");

    int Squaresize = 120;
    int PicArr[6][6] = {0};
    Sprite sprite[20];

    int count = 0;

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) {
            count++;
            sprite[count].setTexture(m);
            sprite[count].setTextureRect(IntRect(i * Squaresize, j * Squaresize, Squaresize, Squaresize));
            PicArr[i + 1][j + 1];

        }
    while (app.isOpen()) {

        Event p;

        while (app.pollEvent(p)) {
            if (p.type == Event::Closed)
                app.close();

            if (p.type == Event::MouseButtonPressed)
                if (p.key.code == Mouse::Left) {

                    Vector2i pos = Mouse::getPosition(app);
                    int x = pos.x / Squaresize + 1;
                    int y = pos.y / Squaresize + 1;

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

                }

        }

        app.clear(Color::Red);
        app.display();
    }

    return 0;
}