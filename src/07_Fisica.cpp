#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <iostream>

using namespace std;

int main()
{
    // Configuración inicial
    float fuerza = 500.0f; 
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Fisica Box2D v3 y SFML");
    ventana.setFramerateLimit(60);

    // 1. CONFIGURACIÓN DEL MUNDO (Box2D v3)
    b2WorldDef worldDef = b2DefaultWorldDef();
    worldDef.gravity = {0.0f, 10.0f}; 
    b2WorldId worldId = b2CreateWorld(&worldDef);

    // 2. CREAR EL SUELO
    b2BodyDef cuerpoSueloDef = b2DefaultBodyDef();
    cuerpoSueloDef.position = {400.0f, 500.0f}; 
    b2BodyId cuerpoSueloId = b2CreateBody(worldId, &cuerpoSueloDef);

    b2Polygon boxShape = b2MakeBox(300.0f, 5.0f); // Mitad del ancho (600/2) y mitad del alto (10/2)
    b2ShapeDef shapeSueloDef = b2DefaultShapeDef();
    shapeSueloDef.friction = 1.0f;
    b2CreatePolygonShape(cuerpoSueloId, &shapeSueloDef, &boxShape);

    // 3. CREAR LA BOLA
    b2BodyDef cuerpoBolaDef = b2DefaultBodyDef();
    cuerpoBolaDef.type = b2_dynamicBody;
    cuerpoBolaDef.position = {400.0f, 300.0f};
    b2BodyId cuerpoBolaId = b2CreateBody(worldId, &cuerpoBolaDef);

    b2Circle circleShape;
    circleShape.center = {0.0f, 0.0f};
    circleShape.radius = 25.0f;

    b2ShapeDef shapeBolaDef = b2DefaultShapeDef();
    shapeBolaDef.density = 1.0f;
    shapeBolaDef.friction = 0.3f;
    shapeBolaDef.restitution = 0.5f;
    b2CreateCircleShape(cuerpoBolaId, &shapeBolaDef, &circleShape);

    // BUCLE PRINCIPAL
    while (ventana.isOpen())
    {
        sf::Event evento;
        while (ventana.pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
                ventana.close();
        }

        // CONTROLES (Box2D v3)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            b2Body_ApplyLinearImpulseToCenter(cuerpoBolaId, {-fuerza, 0.0f}, true);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            b2Body_ApplyLinearImpulseToCenter(cuerpoBolaId, {fuerza, 0.0f}, true);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            b2Body_ApplyLinearImpulseToCenter(cuerpoBolaId, {0.0f, -fuerza}, true);
        
        // ¡Línea corregida!
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
            b2Body_ApplyLinearImpulseToCenter(cuerpoBolaId, {0.0f, fuerza}, true);

        // SIMULACIÓN
        b2World_Step(worldId, 1.0f / 60.0f, 4);

        // DIBUJADO
        b2Vec2 posBola = b2Body_GetPosition(cuerpoBolaId);
        b2Vec2 posSuelo = b2Body_GetPosition(cuerpoSueloId);

        ventana.clear();

        sf::RectangleShape suelo(sf::Vector2f(600.0f, 10.0f));
        suelo.setOrigin(300.0f, 5.0f);
        suelo.setPosition(posSuelo.x, posSuelo.y);
        ventana.draw(suelo);

        sf::CircleShape bola(25.0f);
        bola.setOrigin(25.0f, 25.0f);
        bola.setFillColor(sf::Color::Red);
        bola.setPosition(posBola.x, posBola.y);
        ventana.draw(bola);

        ventana.display();
    }

    b2DestroyWorld(worldId);
    return 0;
}