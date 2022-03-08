#include "EnemyBehaviour.h"
#include <GLFW/glfw3.h>
#include "Utils/ImGuiHelper.h"

// Templated LERP function
template<typename T>
T LERP(const T& p0, const T& p1, float t)
{
	return (1.0f - t) * p0 + t * p1;
}

EnemyBehaviour::~EnemyBehaviour() = default;

EnemyBehaviour::EnemyBehaviour() :
    IComponent(),
	Speed(0.0f),
    LerpMode(false)
{}

void EnemyBehaviour::Awake()
{

    RoutePoint1 = GetPosition();
    RoutePoint2 = GetPosition();
   
}

void EnemyBehaviour::Update(float deltaTime)
{
	lerpTimer += deltaTime * Speed;
	if (lerpTimer >= lerpTimerMax) {
		lerpTimer = 0;
	}
	float t;
	t = lerpTimer / lerpTimerMax;
	GetGameObject()->SetPostion(LERP(RoutePoint1, RoutePoint2, t));
	
}