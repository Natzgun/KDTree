#ifndef KDTREE_RENDER_H
#define KDTREE_RENDER_H

#include "KdTree.h"
#include <SFML/Graphics.hpp>
#include <vector>

class KdTreeRender {
  public:
    KdTreeRender(int width, int height)
        : window(sf::VideoMode(width, height), "KdTree"), width(width),
          height(height) {}

    void render(struct Node *root) {
        window.setFramerateLimit(75);

        while (window.isOpen()) {
            for (sf::Event event; window.pollEvent(event);) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                if (event.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    int point[2] = {mousePos.x, mousePos.y};
                    root = insert(root, point);
                    drawPoint(mousePos.x, mousePos.y);
                    lines.clear();
                    calculateLines(root, 0, 0, width, 0, height);
                }
            }

            window.clear();

            for (const auto &line : lines) {
                window.draw(line);
            }

            for (const auto &point : points) {
                window.draw(point);
            }

            window.display();
        }
    }

  private:
    sf::RenderWindow window;
    int width, height;
    std::vector<sf::CircleShape> points;
    std::vector<sf::VertexArray> lines;

    void drawPoint(float x, float y) {
        sf::CircleShape circle(5.f);
        circle.setFillColor(sf::Color::Cyan);
        circle.setPosition(x - 5, y - 5);
        points.push_back(circle);
    }

    void calculateLines(Node *node, int depth, float xMin, float xMax,
                        float yMin, float yMax) {
        if (node == nullptr)
            return;

        unsigned cd = depth % 2;

        sf::VertexArray line(sf::Lines, 2);
        if (cd == 0) {
            float x = node->point[0];
            line[0].position = sf::Vector2f(x, yMin);
            line[1].position = sf::Vector2f(x, yMax);
        } else {
            float y = node->point[1];
            line[0].position = sf::Vector2f(xMin, y);
            line[1].position = sf::Vector2f(xMax, y);
        }

        line[0].color = sf::Color::White;
        line[1].color = sf::Color::White;
        lines.push_back(line);

        if (cd == 0) {
            calculateLines(node->left, depth + 1, xMin, node->point[0], yMin,
                           yMax);
            calculateLines(node->right, depth + 1, node->point[0], xMax, yMin,
                           yMax);
        } else {
            calculateLines(node->left, depth + 1, xMin, xMax, yMin,
                           node->point[1]);
            calculateLines(node->right, depth + 1, xMin, xMax, node->point[1],
                           yMax);
        }
    }
};

#endif // KDTREE_RENDER_H
