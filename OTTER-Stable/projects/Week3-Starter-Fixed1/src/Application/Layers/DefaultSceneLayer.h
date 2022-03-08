#pragma once
#include "Application/ApplicationLayer.h"
#include "json.hpp"
#include <GLM/glm.hpp>
#include "Utils/Macros.h"
#include "Gameplay/Scene.h"
#include "Gameplay/MeshResource.h"


/**
 * This example layer handles creating a default test scene, which we will use 
 * as an entry point for creating a sample scene
 */
class DefaultSceneLayer final : public ApplicationLayer {
public:
	MAKE_PTRS(DefaultSceneLayer)

	DefaultSceneLayer();
	virtual ~DefaultSceneLayer();

	// Inherited from ApplicationLayer

	virtual void OnAppLoad(const nlohmann::json& config) override;
	void OnUpdate() override;


protected:
	void _CreateScene();
	// The current scene that the application is working on
	Gameplay::Scene::Sptr _currentScene;

	Gameplay::GameObject::Sptr player;
	Gameplay::GameObject::Sptr enemy;
	bool activated = false;

	Texture2D::Sptr    MarioTex = nullptr;
	Texture2D::Sptr    KoopaTex = nullptr;
	Texture2D::Sptr    GroundTex = nullptr;

	bool win = false;
	bool lose = false;
};