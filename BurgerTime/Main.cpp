#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#include <vld.h>
#endif

#include "FPSComponent.h"
#include "GameObject.h"
#include "RenderComponent.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Stream-Engine.h"
#include "TextComponent.h"
#include "TextureComponent.h"

void LoadFunction()
{
	auto& scene = StreamEngine::SceneManager::GetInstance().CreateScene("Demo");

	std::shared_ptr<StreamEngine::GameObject> background{ std::make_shared<StreamEngine::GameObject>() };

	std::shared_ptr<StreamEngine::RenderComponent> pRenderComp{ std::make_shared<StreamEngine::RenderComponent>(background) };

	background->AddComponent(std::make_shared<StreamEngine::TextureComponent>("background.jpg", background, pRenderComp));
	background->AddComponent(pRenderComp);

	scene.Add(background);

	std::shared_ptr<StreamEngine::GameObject> logo{ std::make_shared<StreamEngine::GameObject>() };
	pRenderComp = std::make_shared<StreamEngine::RenderComponent>(logo);

	logo->AddComponent(std::make_shared<StreamEngine::TextureComponent>("logo.png", logo, pRenderComp));
	logo->AddComponent(pRenderComp);
	logo->GetTransform().SetPosition(216, 180, 0);

	scene.Add(logo);

	std::shared_ptr<StreamEngine::GameObject> text{ std::make_shared<StreamEngine::GameObject>() };
	pRenderComp = std::make_shared<StreamEngine::RenderComponent>(text);

	text->AddComponent(std::make_shared<StreamEngine::TextComponent>("Lingua.otf", text, pRenderComp));
	text->AddComponent(pRenderComp);

	text->GetTransform().SetPosition(80, 20, 0);

	text->GetComponent<StreamEngine::TextComponent>()->SetText("Programming 4 Assignment");

	text->GetComponent<StreamEngine::TextComponent>()->SetSize(36);

	scene.Add(text);


	std::shared_ptr<StreamEngine::GameObject> fpsCounter{ std::make_shared<StreamEngine::GameObject>() };
	pRenderComp = std::make_shared<StreamEngine::RenderComponent>(fpsCounter);

	std::shared_ptr<StreamEngine::TextComponent> pTxtComponent{ std::make_shared<StreamEngine::TextComponent>("Lingua.otf",fpsCounter, pRenderComp) };
	pTxtComponent->SetSize(26);
	pTxtComponent->SetColor({ 0,255,0,255 });
	const std::shared_ptr<StreamEngine::FPSComponent> pFPSComponent{ std::make_shared<StreamEngine::FPSComponent>(fpsCounter,pTxtComponent) };

	fpsCounter->AddComponent(pTxtComponent);
	fpsCounter->AddComponent(pFPSComponent);
	fpsCounter->AddComponent(pRenderComp);

	fpsCounter->GetTransform().SetPosition(0, 0, 0);

	scene.Add(fpsCounter);


	StreamEngine::SceneManager::GetInstance().SetActiveScene("Demo");
}

int main(int, char* []) {
	StreamEngine::Streamgin engine{};
	engine.Run(LoadFunction);
	return 0;
}
