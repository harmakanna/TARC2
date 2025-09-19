InsideOutside_EventScript_StudentGiveGalvantula::
	additem ITEM_SPATK_MOCHI, 2
	additem ITEM_SPE_MOCHI, 2
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_GALVANTULA
	givemonwithot OT_PAOLO_GALVANTULA
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, InsideOutside_EventScript_ReceiveGalvantulaParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, InsideOutside_EventScript_ReceiveGalvantulaPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

InsideOutside_EventScript_ReceiveGalvantulaParty::
	call InsideOutside_EventScript_ReceivedGalvantulaFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto InsideOutside_EventScript_FinishStudentQuest
	end
	
InsideOutside_EventScript_ReceiveGalvantulaPC::
	call InsideOutside_EventScript_ReceivedGalvantulaFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto InsideOutside_EventScript_FinishStudentQuest
	end

InsideOutside_EventScript_ReceivedGalvantulaFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_GALVANTULA
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox InsideOutside_Text_YouReceivedGalvantula, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_GALVANTULA
	return

InsideOutside_EventScript_StudentGiveProbopass::
	additem ITEM_DEF_MOCHI, 2
	additem ITEM_SPATK_MOCHI, 2
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_PROBOPASS
	givemonwithot OT_PAOLO_PROBOPASS
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, InsideOutside_EventScript_ReceiveProbopassParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, InsideOutside_EventScript_ReceiveProbopassPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

InsideOutside_EventScript_ReceiveProbopassParty::
	call InsideOutside_EventScript_ReceivedProbopassFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto InsideOutside_EventScript_FinishStudentQuest
	end
	
InsideOutside_EventScript_ReceiveProbopassPC::
	call InsideOutside_EventScript_ReceivedProbopassFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto InsideOutside_EventScript_FinishStudentQuest
	end

InsideOutside_EventScript_ReceivedProbopassFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_PROBOPASS
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox InsideOutside_Text_YouReceivedProbopass, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_PROBOPASS
	return

PastTown_EventScript_FishermanGiveOverqwil::
	additem ITEM_HP_MOCHI, 1
	additem ITEM_ATK_MOCHI, 1
	additem ITEM_SPDEF_MOCHI, 2
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_OVERQWIL
	givemonwithot OT_TEE_OVERQWIL
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PastTown_EventScript_ReceiveOverqwilParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PastTown_EventScript_ReceiveOverqwilPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PastTown_EventScript_ReceiveOverqwilParty::
	call PastTown_EventScript_ReceivedOverqwilFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto PastTown_EventScript_FishermanQuestFinish
	end
	
PastTown_EventScript_ReceiveOverqwilPC::
	call PastTown_EventScript_ReceivedOverqwilFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto PastTown_EventScript_FishermanQuestFinish
	end

PastTown_EventScript_ReceivedOverqwilFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_OVERQWIL
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox PastTown_Text_YouReceivedOverqwil, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_OVERQWIL
	return

PastTown_EventScript_FishermanGiveDragalge::
	additem ITEM_SPDEF_MOCHI, 2
	additem ITEM_SPE_MOCHI, 2
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DRAGALGE
	givemonwithot OT_TEE_DRAGALGE
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PastTown_EventScript_ReceiveDragalgeParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PastTown_EventScript_ReceiveDragalgePC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PastTown_EventScript_ReceiveDragalgeParty::
	call PastTown_EventScript_ReceivedDragalgeFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto PastTown_EventScript_FishermanQuestFinish
	end
	
PastTown_EventScript_ReceiveDragalgePC::
	call PastTown_EventScript_ReceivedDragalgeFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto PastTown_EventScript_FishermanQuestFinish
	end

PastTown_EventScript_ReceivedDragalgeFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_DRAGALGE
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox PastTown_Text_YouReceivedDragalge, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_DRAGALGE
	return

Present_Gym_EventScript_PhoebeGiveDusknoir::
	additem ITEM_ATK_MOCHI, 2
	additem ITEM_SPE_MOCHI, 1
	additem ITEM_SPDEF_MOCHI, 1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DUSKNOIR
    givemonwithot OT_PHOEBE_DUSKNOIR
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Present_Gym_EventScript_ReceiveDusknoirParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Present_Gym_EventScript_ReceiveDusknoirPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Present_Gym_EventScript_ReceiveDusknoirParty::
	call Present_Gym_EventScript_ReceivedDusknoirFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_Gym_EventScript_PhoebeDefeatedSetFlags
	end
	
Present_Gym_EventScript_ReceiveDusknoirPC::
	call Present_Gym_EventScript_ReceivedDusknoirFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_Gym_EventScript_PhoebeDefeatedSetFlags
	end

Present_Gym_EventScript_ReceivedDusknoirFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_DUSKNOIR
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox Present_Gym_Text_YouReceivedDusknoir, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_DUSKNOIR
	return

Present_Gym_EventScript_PhoebeGiveSableye::
	additem ITEM_HP_MOCHI, 1
	additem ITEM_DEF_MOCHI, 1
	additem ITEM_SPDEF_MOCHI, 2
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SABLEYE
	givemonwithot OT_PHOEBE_SABLEYE
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Present_Gym_EventScript_ReceiveSableyeParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Present_Gym_EventScript_ReceiveSableyePC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Present_Gym_EventScript_ReceiveSableyeParty::
	call Present_Gym_EventScript_ReceivedSableyeFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_Gym_EventScript_PhoebeDefeatedSetFlags
	end
	
Present_Gym_EventScript_ReceiveSableyePC::
	call Present_Gym_EventScript_ReceivedSableyeFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_Gym_EventScript_PhoebeDefeatedSetFlags
	end

Present_Gym_EventScript_ReceivedSableyeFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_SABLEYE
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox Present_Gym_Text_YouReceivedSableye, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_SABLEYE
	return

Present_AquaCorpHQ_EventScript_ShellyGiveGorebyss::
	speak LOCALID_AQUACORP_SHELLY, DIR_NORTH, Name_Shelly, Present_AquaCorpHQ_Text_ShellyGorebyssItIs
	closemessage
	delay 20
	applymovement LOCALID_AQUACORP_SARAH, Present_AquaCorpHQ_Movement_SarahGiveDeepSea
	delay 40
	applymovement LOCALID_AQUACORP_SHELLY, Common_Movement_FaceRight
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	speakername Name_Sarah
	msgbox Present_AquaCorpHQ_Text_SarahHereYouGoClamperl, MSGBOX_DEFAULT
	closemessage
	fadeoutbgm 0
	savebgm MUS_NONE
	playmoncry SPECIES_CLAMPERL, CRY_MODE_NORMAL
	waitmoncry
	fadescreen FADE_TO_WHITE
	removeobject LOCALID_CLAMPERL
	clearflag FLAG_HIDE_GOREBYSS
	addobject LOCALID_GOREBYSS
	speakername Name_Sarah
	msgbox Present_AquaCorpHQ_Text_SarahWhoa, MSGBOX_DEFAULT
	closemessage
	delay 40
	fadescreen FADE_FROM_WHITE
	delay 20
	playmoncry SPECIES_GOREBYSS, CRY_MODE_NORMAL
	waitmoncry
	delay 5
	playfanfare MUS_EVOLVED
	msgbox Present_AquaCorpHQ_Text_EvolvedGorebyss
	waitfanfare
	delay 40
	closemessage
	delay 40
	applymovement LOCALID_AQUACORP_SHELLY, Common_Movement_FaceRight
	speak LOCALID_AQUACORP_SARAH, DIR_WEST, Name_Sarah, Present_AquaCorpHQ_Text_SarahThatWasAwesome
	closemessage
	fadeoutbgm 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	speak LOCALID_AQUACORP_SHELLY, DIR_SOUTH, Name_Shelly, Present_AquaCorpHQ_Text_ShellySeeLookerNothingMalicious
	playbgm MUS_PL_LOOKER, FALSE
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_AquaCorpHQ_Text_LookerISupposeAquaIsCleared
	speak LOCALID_AQUACORP_SHELLY, DIR_SOUTH, Name_Shelly, Present_AquaCorpHQ_Text_ShellyImGladToHear
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_AQUACORP_MATT, Present_AquaCorpHQ_Movement_MattApproachLooker
	waitmovement 0
	delay 40
	speakername Name_Matt
	msgbox Present_AquaCorpHQ_Text_MattImSorry, MSGBOX_DEFAULT
	speak LOCALID_PLAYER, DIR_WEST, Name_Looker, Present_AquaCorpHQ_Text_LookerApologyAcceptedImSorry
	closemessage
	applymovement LOCALID_AQUACORP_SARAH, Common_Movement_FaceDownExclamationMark
	applymovement LOCALID_AQUACORP_SHELLY, Common_Movement_FaceRightExclamationMark
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_FaceRightExclamationMark
	delay 48
	applymovement LOCALID_GOREBYSS, Present_AquaCorpHQ_Movement_MonWalkToPlayer
	waitmovement 0
	playmoncry SPECIES_GOREBYSS, CRY_MODE_NORMAL
	waitmoncry
	delay 20
	applymovement LOCALID_AQUACORP_SHELLY, Common_Movement_FaceUp
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	speak LOCALID_AQUACORP_SARAH, DIR_SOUTH, Name_Sarah, Present_AquaCorpHQ_Text_SarahGorebyssWantsToComeWithYou
	playmoncry SPECIES_GOREBYSS, CRY_MODE_NORMAL
	speak LOCALID_GOREBYSS, DIR_NORTH, NULL, Present_AquaCorpHQ_Text_GorebyssExcited
	waitmoncry
	delay 20
	applymovement LOCALID_GOREBYSS, Common_Movement_FaceLeft
	applymovement LOCALID_AQUACORP_SHELLY, Common_Movement_FaceDown
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, Present_AquaCorpHQ_Text_LookerIWillTakeGorebyssAlong
	closemessage
	applymovement LOCALID_AQUACORP_SHELLY, Common_Movement_FaceRight
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	playmoncry SPECIES_GOREBYSS, CRY_MODE_NORMAL
	waitmoncry
	delay 20
	additem ITEM_SPATK_MOCHI, 2
	additem ITEM_SPDEF_MOCHI, 1
	additem ITEM_SPE_MOCHI, 1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_GOREBYSS
    givemonwithot OT_SHELLY_GOREBYSS
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Present_AquaCorpHQ_EventScript_ReceiveGorebyssParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Present_AquaCorpHQ_EventScript_ReceiveGorebyssPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Present_AquaCorpHQ_EventScript_ReceiveGorebyssParty::
	call Present_AquaCorpHQ_EventScript_ReceivedGorebyssFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_AquaCorpHQ_EventScript_FinishAquaGauntlet
	end
	
Present_AquaCorpHQ_EventScript_ReceiveGorebyssPC::
	call Present_AquaCorpHQ_EventScript_ReceivedGorebyssFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_AquaCorpHQ_EventScript_FinishAquaGauntlet
	end

Present_AquaCorpHQ_EventScript_ReceivedGorebyssFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_GOREBYSS
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox Present_AquaCorp_Text_YouReceivedGorebyss, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_GOREBYSS
	return

Present_AquaCorpHQ_EventScript_ShellyGiveHuntail::
	speak LOCALID_AQUACORP_SHELLY, DIR_NORTH, Name_Shelly, Present_AquaCorpHQ_Text_ShellyHuntailItIs
	closemessage
	applymovement LOCALID_AQUACORP_SARAH, Present_AquaCorpHQ_Movement_SarahGiveDeepSea
	delay 10
	speakername Name_Sarah
	applymovement LOCALID_AQUACORP_SHELLY, Common_Movement_FaceRight
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	msgbox Present_AquaCorpHQ_Text_SarahHereYouGoClamperl, MSGBOX_DEFAULT
	closemessage
	fadeoutbgm 0
	savebgm MUS_NONE
	playmoncry SPECIES_CLAMPERL, CRY_MODE_NORMAL
	waitmoncry
	fadescreen FADE_TO_WHITE
	removeobject LOCALID_CLAMPERL
	clearflag FLAG_HIDE_HUNTAIL
	addobject LOCALID_HUNTAIL
	speakername Name_Sarah
	msgbox Present_AquaCorpHQ_Text_SarahWhoa, MSGBOX_DEFAULT
	closemessage
	delay 40
	fadescreen FADE_FROM_WHITE
	delay 20
	playmoncry SPECIES_HUNTAIL, CRY_MODE_NORMAL
	waitmoncry
	delay 5
	playfanfare MUS_EVOLVED
	msgbox Present_AquaCorpHQ_Text_EvolvedHuntail
	waitfanfare
	delay 40
	closemessage
	delay 40
	applymovement LOCALID_AQUACORP_SHELLY, Common_Movement_FaceRight
	speak LOCALID_AQUACORP_SARAH, DIR_WEST, Name_Sarah, Present_AquaCorpHQ_Text_SarahThatWasAwesome
	closemessage
	fadeoutbgm 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	speak LOCALID_AQUACORP_SHELLY, DIR_SOUTH, Name_Shelly, Present_AquaCorpHQ_Text_ShellySeeLookerNothingMalicious
	playbgm MUS_PL_LOOKER, FALSE
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_AquaCorpHQ_Text_LookerISupposeAquaIsCleared
	speak LOCALID_AQUACORP_SHELLY, DIR_SOUTH, Name_Shelly, Present_AquaCorpHQ_Text_ShellyImGladToHear
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_AQUACORP_MATT, Present_AquaCorpHQ_Movement_MattApproachLooker
	waitmovement 0
	delay 40
	speakername Name_Matt
	msgbox Present_AquaCorpHQ_Text_MattImSorry, MSGBOX_DEFAULT
	speak LOCALID_PLAYER, DIR_WEST, Name_Looker, Present_AquaCorpHQ_Text_LookerApologyAcceptedImSorry
	closemessage
	applymovement LOCALID_AQUACORP_SARAH, Common_Movement_FaceDownExclamationMark
	applymovement LOCALID_AQUACORP_SHELLY, Common_Movement_FaceRightExclamationMark
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_FaceRightExclamationMark
	delay 48
	applymovement LOCALID_HUNTAIL, Present_AquaCorpHQ_Movement_MonWalkToPlayer
	waitmovement 0
	playmoncry SPECIES_HUNTAIL, CRY_MODE_NORMAL
	waitmoncry
	delay 20
	applymovement LOCALID_AQUACORP_SHELLY, Common_Movement_FaceUp
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	speak LOCALID_AQUACORP_SARAH, DIR_SOUTH, Name_Sarah, Present_AquaCorpHQ_Text_SarahHuntailWantsToComeWithYou
	playmoncry SPECIES_HUNTAIL, CRY_MODE_NORMAL
	speak LOCALID_HUNTAIL, DIR_NORTH, NULL, Present_AquaCorpHQ_Text_HuntailExcited
	waitmoncry
	delay 20
	applymovement LOCALID_HUNTAIL, Common_Movement_FaceLeft
	applymovement LOCALID_AQUACORP_SHELLY, Common_Movement_FaceDown
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, Present_AquaCorpHQ_Text_LookerIWillTakeHuntailAlong
	closemessage
	applymovement LOCALID_AQUACORP_SHELLY, Common_Movement_FaceRight
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	playmoncry SPECIES_HUNTAIL, CRY_MODE_NORMAL
	waitmoncry
	delay 20
	additem ITEM_ATK_MOCHI, 2
	additem ITEM_DEF_MOCHI, 1
	additem ITEM_SPE_MOCHI, 1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_HUNTAIL
    givemonwithot OT_SHELLY_HUNTAIL
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Present_AquaCorpHQ_EventScript_ReceiveHuntailParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Present_AquaCorpHQ_EventScript_ReceiveHuntailPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Present_AquaCorpHQ_EventScript_ReceiveHuntailParty::
	call Present_AquaCorpHQ_EventScript_ReceivedHuntailFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_AquaCorpHQ_EventScript_FinishAquaGauntlet
	end
	
Present_AquaCorpHQ_EventScript_ReceiveHuntailPC::
	call Present_AquaCorpHQ_EventScript_ReceivedHuntailFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_AquaCorpHQ_EventScript_FinishAquaGauntlet
	end

Present_AquaCorpHQ_EventScript_ReceivedHuntailFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_HUNTAIL
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox Present_AquaCorp_Text_YouReceivedHuntail, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_HUNTAIL
	return

Present_CityHall_2F_Ranger_EventScript_FossilScientistGiveMamoswine::
	additem ITEM_HP_MOCHI, 2
	additem ITEM_ATK_MOCHI, 2
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MAMOSWINE
	givemonwithot OT_LOOKER_MAMOSWINE
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Present_CityHall_2F_Ranger_EventScript_ReceiveMamoswineParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Present_CityHall_2F_Ranger_EventScript_ReceiveMamoswinePC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Present_CityHall_2F_Ranger_EventScript_ReceiveMamoswineParty::
	call Present_CityHall_2F_Ranger_EventScript_ReceivedMamoswineFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_CityHall_2F_Ranger_EventScript_FossilQuestFinish
	end
	
Present_CityHall_2F_Ranger_EventScript_ReceiveMamoswinePC::
	call Present_CityHall_2F_Ranger_EventScript_ReceivedMamoswineFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_CityHall_2F_Ranger_EventScript_FossilQuestFinish
	end

Present_CityHall_2F_Ranger_EventScript_ReceivedMamoswineFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_MAMOSWINE
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox Present_CityHall_2F_Ranger_Text_YouReceivedMamoswine, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_MAMOSWINE
	removeitem ITEM_CLAW_FOSSIL
	return

Present_CityHall_2F_Ranger_EventScript_FossilScientistGiveYanmega::
	additem ITEM_SPATK_MOCHI, 2
	additem ITEM_SPE_MOCHI, 2
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_YANMEGA
	givemonwithot OT_LOOKER_YANMEGA
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Present_CityHall_2F_Ranger_EventScript_ReceiveYanmegaParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Present_CityHall_2F_Ranger_EventScript_ReceiveYanmegaPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Present_CityHall_2F_Ranger_EventScript_ReceiveYanmegaParty::
	call Present_CityHall_2F_Ranger_EventScript_ReceivedYanmegaFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_CityHall_2F_Ranger_EventScript_FossilQuestFinish
	end
	
Present_CityHall_2F_Ranger_EventScript_ReceiveYanmegaPC::
	call Present_CityHall_2F_Ranger_EventScript_ReceivedYanmegaFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_CityHall_2F_Ranger_EventScript_FossilQuestFinish
	end

Present_CityHall_2F_Ranger_EventScript_ReceivedYanmegaFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_YANMEGA
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox Present_CityHall_2F_Ranger_Text_YouReceivedYanmega, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_YANMEGA
	removeitem ITEM_ROOT_FOSSIL
	return

Present_Cafe_EventScript_EmmaGiveGumshoos::
	additem ITEM_HP_MOCHI, 1
	additem ITEM_ATK_MOCHI, 1
	additem ITEM_DEF_MOCHI, 1
	additem ITEM_SPDEF_MOCHI, 1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_GUMSHOOS
	givemonwithot OT_EMMA_GUMSHOOS
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Present_Cafe_EventScript_ReceiveGumshoosParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Present_Cafe_EventScript_ReceiveGumshoosPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Present_Cafe_EventScript_ReceiveGumshoosParty::
	call Present_Cafe_EventScript_ReceivedGumshoosFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_Cafe_EventScript_EmmaFinishQuest
	end
	
Present_Cafe_EventScript_ReceiveGumshoosPC::
	call Present_Cafe_EventScript_ReceivedGumshoosFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_Cafe_EventScript_EmmaFinishQuest
	end

Present_Cafe_EventScript_ReceivedGumshoosFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_GUMSHOOS
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox Present_Cafe_Text_YouReceivedGumshoos, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_GUMSHOOS
	return

Present_Cafe_EventScript_EmmaGiveMeowstic::
	additem ITEM_SPATK_MOCHI, 2
	additem ITEM_SPE_MOCHI, 2
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MEOWSTIC
	givemonwithot OT_EMMA_MEOWSTIC
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Present_Cafe_EventScript_ReceiveMeowsticParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Present_Cafe_EventScript_ReceiveMeowsticPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Present_Cafe_EventScript_ReceiveMeowsticParty::
	call Present_Cafe_EventScript_ReceivedMeowsticFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_Cafe_EventScript_EmmaFinishQuest
	end
	
Present_Cafe_EventScript_ReceiveMeowsticPC::
	call Present_Cafe_EventScript_ReceivedMeowsticFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_Cafe_EventScript_EmmaFinishQuest
	end

Present_Cafe_EventScript_ReceivedMeowsticFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_MEOWSTIC
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox Present_Cafe_Text_YouReceivedMeowstic, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_MEOWSTIC
	return


PastTown_EventScript_ForemanGiveBreloom::
	additem ITEM_ATK_MOCHI, 2
	additem ITEM_SPE_MOCHI, 2
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BRELOOM
	givemonwithot OT_LOOKER_BRELOOM
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PastTown_EventScript_ReceiveBreloomParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PastTown_EventScript_ReceiveBreloomPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PastTown_EventScript_ReceiveBreloomParty::
	call PastTown_EventScript_ReceivedBreloomFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto PastTown_EventScript_ForemanQuestFinish
	end
	
PastTown_EventScript_ReceiveBreloomPC::
	call PastTown_EventScript_ReceivedBreloomFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto PastTown_EventScript_ForemanQuestFinish
	end

PastTown_EventScript_ReceivedBreloomFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_BRELOOM
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox PastTown_Text_YouReceivedBreloom, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_BRELOOM
	return

PastTown_EventScript_ForemanGiveShiinotic::
	additem ITEM_HP_MOCHI, 2
	additem ITEM_DEF_MOCHI, 1
	additem ITEM_SPDEF_MOCHI, 1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SHIINOTIC
	givemonwithot OT_LOOKER_SHIINOTIC
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PastTown_EventScript_ReceiveShiinoticParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PastTown_EventScript_ReceiveShiinoticPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PastTown_EventScript_ReceiveShiinoticParty::
	call PastTown_EventScript_ReceivedShiinoticFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto PastTown_EventScript_ForemanQuestFinish
	end
	
PastTown_EventScript_ReceiveShiinoticPC::
	call PastTown_EventScript_ReceivedShiinoticFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto PastTown_EventScript_ForemanQuestFinish
	end

PastTown_EventScript_ReceivedShiinoticFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_SHIINOTIC
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox PastTown_Text_YouReceivedShiinotic, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_SHIINOTIC
	return

PastTown_EventScript_SadGirlGiveTauros::
	additem ITEM_ATK_MOCHI, 2
	additem ITEM_DEF_MOCHI, 1
	additem ITEM_SPE_MOCHI, 1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAUROS
	givemonwithot OT_ALICE_TAUROS
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PastTown_EventScript_ReceiveTaurosParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PastTown_EventScript_ReceiveTaurosPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PastTown_EventScript_ReceiveTaurosParty::
	call PastTown_EventScript_ReceivedTaurosFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_1, LOCALID_TAUROS
	setvar VAR_TEMP_2, LOCALID_MILTANK
	goto PastTown_EventScript_SadGirlQuestFinish
	end
	
PastTown_EventScript_ReceiveTaurosPC::
	call PastTown_EventScript_ReceivedTaurosFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_1, LOCALID_TAUROS
	setvar VAR_TEMP_2, LOCALID_MILTANK
	goto PastTown_EventScript_SadGirlQuestFinish
	end

PastTown_EventScript_ReceivedTaurosFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_TAUROS
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox PastTown_Text_YouReceivedTauros, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_TAUROS
	return

PastTown_EventScript_SadGirlGiveMiltank::
	additem ITEM_HP_MOCHI, 2
	additem ITEM_SPE_MOCHI, 2
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MILTANK
	givemonwithot OT_ALICE_MILTANK
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PastTown_EventScript_ReceiveMiltankParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PastTown_EventScript_ReceiveMiltankPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PastTown_EventScript_ReceiveMiltankParty::
	call PastTown_EventScript_ReceivedMiltankFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_1, LOCALID_MILTANK
	setvar VAR_TEMP_2, LOCALID_TAUROS
	goto PastTown_EventScript_SadGirlQuestFinish
	end
	
PastTown_EventScript_ReceiveMiltankPC::
	call PastTown_EventScript_ReceivedMiltankFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_1, LOCALID_MILTANK
	setvar VAR_TEMP_2, LOCALID_TAUROS
	goto PastTown_EventScript_SadGirlQuestFinish
	end

PastTown_EventScript_ReceivedMiltankFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_MILTANK
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox PastTown_Text_YouReceivedMiltank, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_MILTANK
	return

PresentTown_Port_EventScript_BlueGiveGolem::
	additem ITEM_ATK_MOCHI, 1
	additem ITEM_DEF_MOCHI, 2
	additem ITEM_SPDEF_MOCHI, 1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_GOLEM
	givemonwithot OT_BLUE_GOLEM
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PresentTown_Port_EventScript_ReceiveGolemParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PresentTown_Port_EventScript_ReceiveGolemPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PresentTown_Port_EventScript_ReceiveGolemParty::
	call PresentTown_Port_EventScript_ReceivedGolemFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BLUE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PresentTown_Port_EventScript_ReceiveGolemPC::
	call PresentTown_Port_EventScript_ReceivedGolemFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BLUE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
	
PresentTown_Port_EventScript_ReceivedGolemFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_GOLEM
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox PresentTown_Port_Text_YouReceivedGolem, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_GOLEM
	return

PresentTown_Port_EventScript_BlueGiveMachamp::
	additem ITEM_HP_MOCHI, 1
	additem ITEM_ATK_MOCHI, 2
	additem ITEM_SPE_MOCHI, 1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MACHAMP
	givemonwithot OT_BLUE_MACHAMP
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PresentTown_Port_EventScript_ReceiveMachampParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PresentTown_Port_EventScript_ReceiveMachampPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PresentTown_Port_EventScript_ReceiveMachampParty::
	call PresentTown_Port_EventScript_ReceivedMachampFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BLUE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PresentTown_Port_EventScript_ReceiveMachampPC::
	call PresentTown_Port_EventScript_ReceivedMachampFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BLUE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
	
PresentTown_Port_EventScript_ReceivedMachampFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_MACHAMP
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox PresentTown_Port_Text_YouReceivedMachamp, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_MACHAMP
	return

Present_Cafe_EventScript_MayGiveWalrein::
	additem ITEM_HP_MOCHI, 2
	additem ITEM_ATK_MOCHI, 1
	additem ITEM_SPATK_MOCHI, 1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_WALREIN
	givemonwithot OT_MAY_WALREIN
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Present_Cafe_EventScript_ReceiveWalreinParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Present_Cafe_EventScript_ReceiveWalreinPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Present_Cafe_EventScript_ReceiveWalreinParty::
	call Present_Cafe_EventScript_ReceivedWalreinFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAFE_MAY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
	
Present_Cafe_EventScript_ReceiveWalreinPC::
	call Present_Cafe_EventScript_ReceivedWalreinFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAFE_MAY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_Cafe_EventScript_ReceivedWalreinFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_WALREIN
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox Present_Cafe_Text_YouReceivedWalrein, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_WALREIN
	return

Present_Cafe_EventScript_MayGiveCamerupt::
	additem ITEM_HP_MOCHI, 1
	additem ITEM_DEF_MOCHI, 1
	additem ITEM_SPATK_MOCHI, 1
	additem ITEM_SPDEF_MOCHI, 1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CAMERUPT
	givemonwithot OT_MAY_CAMERUPT
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Present_Cafe_EventScript_ReceiveCameruptParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Present_Cafe_EventScript_ReceiveCameruptPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Present_Cafe_EventScript_ReceiveCameruptParty::
	call Present_Cafe_EventScript_ReceivedCameruptFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAFE_MAY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_Cafe_EventScript_ReceiveCameruptPC::
	call Present_Cafe_EventScript_ReceivedCameruptFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAFE_MAY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_Cafe_EventScript_ReceivedCameruptFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_CAMERUPT
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox Present_Cafe_Text_YouReceivedCamerupt, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CAMERUPT
	return

Present_Cafe_EventScript_LisiaGiveMisdreavus::
	additem ITEM_SPATK_MOCHI, 1
	additem ITEM_SPDEF_MOCHI, 2
	additem ITEM_SPE_MOCHI, 1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MISDREAVUS
	givemonwithot OT_LISIA_MISDREAVUS
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Present_Cafe_EventScript_ReceiveMisdreavusParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Present_Cafe_EventScript_ReceiveMisdreavusPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Present_Cafe_EventScript_ReceiveMisdreavusParty::
	call Present_Cafe_EventScript_ReceivedMisdreavusFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_Cafe_EventScript_LisiaFinishQuest
	end
	
Present_Cafe_EventScript_ReceiveMisdreavusPC::
	call Present_Cafe_EventScript_ReceivedMisdreavusFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_Cafe_EventScript_LisiaFinishQuest
	end

Present_Cafe_EventScript_ReceivedMisdreavusFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_MISDREAVUS
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox Present_Cafe_Text_YouReceivedMisdreavus, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_MISDREAVUS
	return

Present_Cafe_EventScript_LisiaGiveMurkrow::
	additem ITEM_HP_MOCHI, 1
	additem ITEM_ATK_MOCHI, 1
	additem ITEM_SPDEF_MOCHI, 1
	additem ITEM_SPE_MOCHI, 1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MURKROW
	givemonwithot OT_LISIA_MURKROW
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Present_Cafe_EventScript_ReceiveMurkrowParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Present_Cafe_EventScript_ReceiveMurkrowPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Present_Cafe_EventScript_ReceiveMurkrowParty::
	call Present_Cafe_EventScript_ReceivedMurkrowFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_Cafe_EventScript_LisiaFinishQuest
	end
	
Present_Cafe_EventScript_ReceiveMurkrowPC::
	call Present_Cafe_EventScript_ReceivedMurkrowFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_Cafe_EventScript_LisiaFinishQuest
	end

Present_Cafe_EventScript_ReceivedMurkrowFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_MURKROW
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox Present_Cafe_Text_YouReceivedMurkrow, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_MURKROW
	return

Present_Flat1_2F_EventScript_BeautyGiveSwanna::
	additem ITEM_HP_MOCHI, 2
	additem ITEM_DEF_MOCHI, 1
	additem ITEM_SPATK_MOCHI, 1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SWANNA
	givemonwithot OT_BEATRICE_SWANNA
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Present_Flat1_2F_EventScript_ReceiveSwannaParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Present_Flat1_2F_EventScript_ReceiveSwannaPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Present_Flat1_2F_EventScript_ReceiveSwannaParty::
	call Present_Flat1_2F_EventScript_ReceivedSwannaFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_Flat1_2F_EventScript_BeautyFinishQuest
	end
	
Present_Flat1_2F_EventScript_ReceiveSwannaPC::
	call Present_Flat1_2F_EventScript_ReceivedSwannaFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_Flat1_2F_EventScript_BeautyFinishQuest
	end

Present_Flat1_2F_EventScript_ReceivedSwannaFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_SWANNA
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox Present_Flat1_2F_Text_YouReceivedSwanna, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_SWANNA
	return

Present_Flat1_2F_EventScript_BeautyGiveUnfezant::
	additem ITEM_HP_MOCHI, 1
	additem ITEM_SPATK_MOCHI, 2
	additem ITEM_SPE_MOCHI, 1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_UNFEZANT
	givemonwithot OT_BEATRICE_UNFEZANT
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Present_Flat1_2F_EventScript_ReceiveUnfezantParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Present_Flat1_2F_EventScript_ReceiveUnfezantPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Present_Flat1_2F_EventScript_ReceiveUnfezantParty::
	call Present_Flat1_2F_EventScript_ReceivedUnfezantFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_Flat1_2F_EventScript_BeautyFinishQuest
	end
	
Present_Flat1_2F_EventScript_ReceiveUnfezantPC::
	call Present_Flat1_2F_EventScript_ReceivedUnfezantFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto Present_Flat1_2F_EventScript_BeautyFinishQuest
	end

Present_Flat1_2F_EventScript_ReceivedUnfezantFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_UNFEZANT
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox Present_Flat1_2F_Text_YouReceivedUnfezant, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_UNFEZANT
	return

InsideOutside_EventScript_ArtistGiveSmeargle::
	additem ITEM_HP_MOCHI, 1
	additem ITEM_ATK_MOCHI, 1
	additem ITEM_DEF_MOCHI, 1
	additem ITEM_SPATK_MOCHI, 1
	additem ITEM_SPDEF_MOCHI, 1
	additem ITEM_SPE_MOCHI, 1
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SMEARGLE
	givemonwithot OT_LEO_SMEARGLE
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, InsideOutside_EventScript_ReceiveSmeargleParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, InsideOutside_EventScript_ReceiveSmearglePC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

InsideOutside_EventScript_ReceiveSmeargleParty::
	call InsideOutside_EventScript_ReceivedSmeargleFanfare
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto InsideOutside_EventScript_ArtistFinishQuest
	end
	
InsideOutside_EventScript_ReceiveSmearglePC::
	call InsideOutside_EventScript_ReceivedSmeargleFanfare
	call Common_EventScript_TransferredToPC
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	closemessage
	goto InsideOutside_EventScript_ArtistFinishQuest
	end

InsideOutside_EventScript_ReceivedSmeargleFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_SMEARGLE
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox InsideOutside_Text_YouReceivedSmeargle, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_SMEARGLE
	return
	
InsideOutside_Text_YouReceivedSmeargle:
	.string "Smeargle joined your party!$"
	
Present_Flat1_2F_Text_YouReceivedSwanna:
	.string "You received a Swanna!$"

Present_Flat1_2F_Text_YouReceivedUnfezant:
	.string "You received an Unfezant!$"

PresentTown_Port_Text_YouReceivedGolem:
	.string "Blue gave you his Golem!$"

PresentTown_Port_Text_YouReceivedMachamp:
	.string "Blue gave you his Machamp!$"

Present_Cafe_Text_YouReceivedWalrein:
	.string "May gave you her Walrein!$"

Present_Cafe_Text_YouReceivedCamerupt:
	.string "May gave you her Camerupt!$"

Present_Cafe_Text_YouReceivedMisdreavus:
	.string "Lisia gave you her Misdreavus!$"

Present_Cafe_Text_YouReceivedMurkrow:
	.string "Lisia gave you her Murkrow!$"

PastTown_Text_YouReceivedTauros:
	.string "Torin joined your party!$"

PastTown_Text_YouReceivedMiltank:
	.string "Moomoo joined your party!$"

PastTown_Text_YouReceivedBreloom:
	.string "Looker received a Breloom!$"

PastTown_Text_YouReceivedShiinotic:
	.string "Looker received a Shiinotic!$"
	
Present_Cafe_Text_YouReceivedGumshoos:
	.string "Emma gave you her Gumshoos!$"

Present_Cafe_Text_YouReceivedMeowstic:
	.string "Emma gave you her Meowstic!$"

Present_CityHall_2F_Ranger_Text_YouReceivedMamoswine:
	.string "You revived a Mamoswine!$"

Present_CityHall_2F_Ranger_Text_YouReceivedYanmega:
	.string "You revived a Yanmega!$"

Present_AquaCorp_Text_YouReceivedGorebyss:
	.string "Gorb joined your party!$"

Present_AquaCorp_Text_YouReceivedHuntail:
	.string "Huntsman joined your party!$"

Present_Gym_Text_YouReceivedDusknoir:
	.string "You received a Dusknoir!$"

Present_Gym_Text_YouReceivedSableye:
	.string "You received a Sableye!$"

PastTown_Text_YouReceivedOverqwil:
	.string "You received an Overqwil!$"

PastTown_Text_YouReceivedDragalge:
	.string "You received a Dragalge!$"

InsideOutside_Text_YouReceivedGalvantula:
	.string "You received a Galvantula!$"

InsideOutside_Text_YouReceivedProbopass:
	.string "You received a Probopass!$"
	