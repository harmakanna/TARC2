Past_House1_MapScripts::
	.byte 0

Past_House1_EventScript_SadGirl::
	lock
	call Script_GetNPCFacingDirection
	returnqueststate QUEST_SENT_TO_THE_FARM
	switch VAR_RESULT
	case 1, Past_House1_EventScript_SadGirlQuestActivate
	case 2, Past_House1_EventScript_SadGirlQuestActive
	case 3, Past_House1_EventScript_SadGirlQuestReward
	case 4, Past_House1_EventScript_SadGirlQuestComplete
	release
	end

Past_House1_EventScript_SadGirlQuestActivate::
	startquest QUEST_SENT_TO_THE_FARM
	release
	end

Past_House1_EventScript_SadGirlQuestActive::
	release
	end

Past_House1_EventScript_SadGirlQuestReward::
	release
	end

Past_House1_EventScript_SadGirlQuestComplete::
	release
	end