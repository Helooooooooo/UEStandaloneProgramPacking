// Copyright Epic Games, Inc. All Rights Reserved.


#include "MyProgram.h"

#include "RequiredProgramMainCPPInclude.h"
#include "StandaloneRenderer.h"
#include "Framework/Application/SlateApplication.h"

DEFINE_LOG_CATEGORY_STATIC(LogMyProgram, Log, All);

IMPLEMENT_APPLICATION(MyProgram, "MyProgram");

int WINAPI WinMain( _In_ HINSTANCE hInInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR, _In_ int nCmdShow )
{
	GEngineLoop.PreInit(GetCommandLineW());

	FSlateApplication::InitializeAsStandaloneApplication(GetStandardStandaloneRenderer());

	FSlateApplication::InitHighDPI(true);
	
	TSharedRef<SWindow> Window = SNew(SWindow)
	.ClientSize(FVector2D(200.f, 200.f))
	[
		SNullWidget::NullWidget
	];
	
	FSlateApplication::Get().AddWindow(Window);
	
	while (!IsEngineExitRequested())
	{
		BeginExitIfRequested();
		
		FSlateApplication::Get().PumpMessages();
		FSlateApplication::Get().Tick();
	}
	
	FSlateApplication::Shutdown();

	GEngineLoop.AppPreExit();
	GEngineLoop.AppExit();

	return 0;
}
