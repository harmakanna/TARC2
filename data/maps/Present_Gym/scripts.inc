Present_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Present_Gym_OnTransition
	.byte 0

Present_Gym_OnTransition:
	call Present_Gym_EventScript_SetFlashLevel
	end

Present_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_PHOEBE, Present_Gym_EventScript_SetLightsOn
	call Present_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, Present_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, Present_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, Present_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, Present_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, Present_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, Present_Gym_EventScript_SetFlashLevel2
	goto Present_Gym_EventScript_SetFlashLevel1

Present_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
Present_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

Present_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

Present_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

Present_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

Present_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

Present_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
Present_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

Present_Gym_EventScript_BrightenRoom::
	call Present_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, Present_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, Present_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, Present_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, Present_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, Present_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, Present_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, Present_Gym_EventScript_AnimateFlash6Trainers

Present_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
Present_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call Present_Gym_EventScript_SetFlashLevel
	return

Present_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call Present_Gym_EventScript_SetFlashLevel
	return

Present_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call Present_Gym_EventScript_SetFlashLevel
	return

Present_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call Present_Gym_EventScript_SetFlashLevel
	return

Present_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call Present_Gym_EventScript_SetFlashLevel
	return

Present_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call Present_Gym_EventScript_SetFlashLevel
	return

Present_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call Present_Gym_EventScript_SetFlashLevel
	return

Present_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, Present_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
Present_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, Present_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
Present_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, Present_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
Present_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, Present_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
Present_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, Present_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
Present_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, Present_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
Present_Gym_EventScript_StopCountingTrainers::
	return