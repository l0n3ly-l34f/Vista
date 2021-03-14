#include "Vista/Core/Application.hpp"

#include "Vista/Scene/SceneManager.hpp"
#include "Vista/Scene/Scene.hpp"

#include "Vista/Graphics/Renderer.hpp"
#include "Vista/Graphics/Color.hpp"

#include "Vista/Audio/AudioPlayer.hpp"

#include "Vista/Math/Vector2D.hpp"

#include "raylib.h"

Vista::Application::Application()
{
	
}

Vista::Application::~Application()
{

}

void Vista::Application::Run(int argc, char* argv[])
{
	::InitWindow(640, 480, "Application Powered by Vista");
	::SetTargetFPS(60);
	::InitAudioDevice();
	while (!(::WindowShouldClose()))
	{
		Vista::AudioPlayer::Update();
		Vista::Renderer::StartDrawing();
		Vista::Renderer::Clear({ 255, 255, 255, 255 });
		if (!(Vista::SceneManager::IsEmpty()))
		{
			Vista::SceneManager::GetActiveScenePointer()->Update(::GetFrameTime());
			Vista::SceneManager::GetActiveScenePointer()->Input();
			Vista::SceneManager::GetActiveScenePointer()->Draw();
		}
		Vista::Renderer::DrawFPS({ 0.0f, 0.0f });
		Vista::Renderer::EndDrawing();
	}
	::CloseAudioDevice();
	::CloseWindow();
}