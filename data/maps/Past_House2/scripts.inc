Past_House2_MapScripts::
	.byte 0

Past_House2_EventScript_SweetToothGirl::
	lock
	faceplayer
	call Script_GetNPCFacingDirection
	returnqueststate QUEST_FIND_TASTY_MINT
	switch VAR_RESULT
	case 1, Past_House2_EventScript_SweetToothGirlActivate
	case 2, Past_House2_EventScript_SweetToothGirlActive
	case 3, Past_House2_EventScript_SweetToothGirlReward
	case 4, Past_House2_EventScript_SweetToothGirlComplete
	release
	end

Past_House2_EventScript_SweetToothGirlActivate::
	release
	end
	
Past_House2_EventScript_SweetToothGirlActive::
	release
	end

Past_House2_EventScript_SweetToothGirlReward::
	release
	end

Past_House2_EventScript_SweetToothGirlComplete::
	release
	end