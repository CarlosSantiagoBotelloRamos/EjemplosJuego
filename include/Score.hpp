#ifndef SCORE_HPP
#define SCORE_HPP

class Score
{
private:
    int points;
    float distanceTraveled;
    int nearMisses;
    float maxVelocity;
    int collisions;
    float timeAlive;
    
public:
    Score();
    
    void update(float deltaTime, float playerVelocity);
    void addPoints(int pts);
    void recordNearMiss();
    void recordCollision();
    void updateDistance(float distance);
    void updateMaxVelocity(float velocity);
    
    int getPoints() const;
    float getDistance() const;
    int getNearMisses() const;
    float getMaxVelocity() const;
    int getCollisions() const;
    float getTimeAlive() const;
    
    void reset();
};

#endif
