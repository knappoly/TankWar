#pragma once
#include <vector>
#include <stack>
#include "Engine/Core/Rgba.hpp"
#include "Engine/math/Vector3.hpp"

//-----------------------------------------------------------------------------------------------
// Forward declarations
class Command;
class Clock;
class GameState;
class Camera;
class StopWatch;

//-----------------------------------------------------------------------------------------------
class Game
{
public:
	//-----------------------------------------------------------------------------------------------
	// Constructor/Destructor
	Game();
	~Game();

	//-----------------------------------------------------------------------------------------------
	// Accessors
			

	//-----------------------------------------------------------------------------------------------
	// Member functions
			void					Initialize();
			void					LoadAudioFiles();
			void					PushState( GameState* state );
			void					PopState();
			void					ChangeState( GameState* state );
			void					ProcessStates( float deltaSeconds );
			void					RenderTopState() const;
			void					Update(); // uses game clock's delta seconds
			void					Render() const;

	//-----------------------------------------------------------------------------------------------
	// Static Functions
	static	Game*					CreateInstance();
	static	Game*					GetInstance();
	static	void					DestroyInstance();
	static	bool					IsPaused();
	static	bool					IsTimeSlow();

	//-----------------------------------------------------------------------------------------------
	// Command Callbacks
	
	//-----------------------------------------------------------------------------------------------
	// Member Variables
	Clock*					m_gameClock = nullptr;
	Camera*					m_gameCamera = nullptr;
	std::stack<GameState*>	m_stateStack;
	bool					m_isChangingState = false;
	StopWatch*				m_fadeTimer;
};

