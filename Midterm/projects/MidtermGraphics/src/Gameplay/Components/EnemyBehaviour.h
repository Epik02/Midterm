#pragma once
#include "IComponent.h"
#include "Gameplay/GameObject.h"
#include "Gameplay/Scene.h"
#include "Gameplay/Components/RenderComponent.h"
class EnemyBehaviour :public Gameplay::IComponent 
{
public:
	typedef std::shared_ptr<EnemyBehaviour> Sptr;

	EnemyBehaviour();
	virtual ~EnemyBehaviour();

	virtual void Awake() override;
	virtual void Update(float deltaTime) override;
	MAKE_TYPENAME(EnemyBehaviour);
	virtual nlohmann::json ToJson() const override;
	static EnemyBehaviour::Sptr FromJson(const nlohmann::json& blob);
	virtual void RenderImGui() override;
	glm::vec3 GetPosition();

	float Speed;
	glm::vec3 RoutePoint1;
	glm::vec3 RoutePoint2;
	

	float lerpTimer = 0;
	float lerpTimerMax = 10.0f;

	bool LerpMode;
};

