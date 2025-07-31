Present_AquaCorpHQ_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Present_AquaCorpHQ_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, Present_AquaCorpHQ_OnResume
	.byte 0

Present_AquaCorpHQ_OnFrame:
	call_if_lt VAR_AQUACORP_STATE, 2, Present_AquaCorpHQ_EventScript_StartAquaGauntlet
	.2byte 0

Present_AquaCorpHQ_OnResume:
	special HealPlayerParty
	end

Present_AquaCorpHQ_EventScript_StartAquaGauntlet::
	lockall
	applymovement LOCALID_PLAYER, Present_AquaCorpHQ_Movement_LookerApproachMatt
	goto_if_eq VAR_AQUACORP_STATE, 1, Present_AquaCorpHQ_StartAquaGauntletRematch
	setvar VAR_AQUACORP_STATE, 1
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_AquaCorpHQ_Text_LookerMatt
	delay 10
	playse SE_PIN
	applymovement LOCALID_AQUACORP_MATT, Common_Movement_FaceDownExclamationMark
	applymovement LOCALID_AQUACORP_SHELDON, Common_Movement_FaceDownExclamationMark
	delay 48
	speak LOCALID_AQUACORP_MATT, DIR_SOUTH, Name_Matt, Present_AquaCorpHQ_Text_MattWhyAreYouHere
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_AquaCorpHQ_Text_LookerYoureUnderArrest
	closemessage
	delay 40
	speak LOCALID_AQUACORP_MATT, DIR_SOUTH, Name_Matt, Present_AquaCorpHQ_Text_MattWhat
	closemessage
	delay 60
	applymovement LOCALID_AQUACORP_MATT, Common_Movement_FaceLeft
	delay 60
	applymovement LOCALID_AQUACORP_MATT, Common_Movement_FaceRight
	delay 60
	applymovement LOCALID_AQUACORP_MATT, Common_Movement_FaceDown
	waitmovement 0
	speakername Name_Matt
	msgbox Present_AquaCorpHQ_Text_MattDots, MSGBOX_DEFAULT
	closemessage
	delay 40
	speak LOCALID_AQUACORP_MATT, DIR_SOUTH, Name_Matt, Present_AquaCorpHQ_Text_MattOhComeOn
	applymovement LOCALID_AQUACORP_GRUNTF_TABLE, Present_AquaCorpHQ_Movement_FaceRightQuestionMark
	applymovement LOCALID_AQUACORP_GRUNTM_WAILMER, Present_AquaCorpHQ_Movement_FaceUpQuestionMark
	applymovement LOCALID_AQUACORP_SCIENTIST_WAILMER, Common_Movement_FaceUp
	applymovement LOCALID_AQUACORP_GRUNTM_TABLE, Common_Movement_WalkInPlaceFasterRight
	call_if_unset FLAG_SYS_WEATHER_CTRL, Present_AquaCorpHQ_EventScript_LookerWasAStorm
	call_if_set FLAG_SYS_WEATHER_CTRL, Present_AquaCorpHQ_EventScript_LookerIsAStorm
	speak LOCALID_AQUACORP_MATT, DIR_SOUTH, Name_Matt, Present_AquaCorpHQ_Text_MattSoWhatIfTheresAStorm
	call_if_unset FLAG_DEFEATED_SHRINE_GENIES, Present_AquaCorpHQ_EventScript_LookerGoodIntel
	call_if_set FLAG_DEFEATED_SHRINE_GENIES, Present_AquaCorpHQ_EventScript_LookerConfirmed
	playse SE_SELECT
	applymovement LOCALID_AQUACORP_GRUNTM_TABLE, Present_AquaCorpHQ_Movement_TableGruntMWalkToSee
	applymovement LOCALID_AQUACORP_SCIENTIST_WAILMER, Present_AquaCorpHQ_Movement_WailmerScientistWalkToSee
	applymovement LOCALID_AQUACORP_GRUNTF_TABLE, Present_AquaCorpHQ_Movement_TableGruntFWalkToSee
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_AquaCorpHQ_Text_LookerJustThreeMonthsAgo
	speak LOCALID_AQUACORP_MATT, DIR_SOUTH, Name_Matt, Present_AquaCorpHQ_Text_MattGrr
	applymovement LOCALID_AQUACORP_SHELLY, Common_Movement_WalkLeft
	speakername Name_Shelly
	msgbox Present_AquaCorpHQ_Text_ShellyWillYouJustStop, MSGBOX_DEFAULT
	speak LOCALID_AQUACORP_MATT, DIR_EAST, Name_Matt, Present_AquaCorpHQ_Text_MattNoIWillNot
	playse SE_PIN
	speak LOCALID_AQUACORP_MATT, DIR_SOUTH, Name_Matt, Present_AquaCorpHQ_Text_MattEnoughOfThis
	closemessage
	goto Present_AquaCorpHQ_EventScript_AquaGauntlet
	end

Present_AquaCorpHQ_EventScript_LookerWasAStorm::
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_AquaCorpHQ_Text_LookerThereWasAStorm
	return

Present_AquaCorpHQ_EventScript_LookerIsAStorm::
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_AquaCorpHQ_Text_LookerThereIsAStorm
	return

Present_AquaCorpHQ_EventScript_LookerGoodIntel::
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_AquaCorpHQ_Text_LookerWeHaveItOnGoodIntel
	return

Present_AquaCorpHQ_EventScript_LookerConfirmed::
	call_if_set FLAG_SYS_WEATHER_CTRL, Present_AquaCorpHQ_EventScript_ConfirmedIs
	call_if_unset FLAG_SYS_WEATHER_CTRL, Present_AquaCorpHQ_EventScript_ConfirmedWas
	return

Present_AquaCorpHQ_EventScript_ConfirmedIs::
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_AquaCorpHQ_Text_LookerWeHaveConfirmedAreBeing
	return

Present_AquaCorpHQ_EventScript_ConfirmedWas::
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_AquaCorpHQ_Text_LookerWeHaveConfirmed
	return

Present_AquaCorpHQ_EventScript_StartAquaGauntletRematch::
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_AquaCorpHQ_Text_LookerImBack
	speak LOCALID_AQUACORP_MATT, DIR_SOUTH, Name_Matt, Present_AquaCorpHQ_Text_MattYouWantMore
	speak LOCALID_AQUACORP_SHELLY, DIR_WEST, Name_Shelly, Present_AquaCorpHQ_Text_ShellyThisIsntHelping
	speak LOCALID_AQUACORP_MATT, DIR_EAST, Name_Matt, Present_AquaCorpHQ_Text_MattTheGuyWontLeaveUsAlone
	playse SE_SELECT
	speak LOCALID_AQUACORP_MATT, DIR_SOUTH, Name_Matt, Present_AquaCorpHQ_Text_MattWeGottaTeachHim
	closemessage
	clearflag FLAG_DEFEATED_GRUNT_1
	clearflag FLAG_DEFEATED_GRUNT_2
	clearflag FLAG_DEFEATED_GRUNT_3
	goto Present_AquaCorpHQ_EventScript_AquaGauntlet
	end

@ First grunt: TRAINER_GRUNT_AQUA_HIDEOUT_1
Present_AquaCorpHQ_EventScript_AquaGauntlet::
	applymovement LOCALID_AQUACORP_SHELDON, Present_AquaCorpHQ_Movement_SheldonRushLooker
	applymovement LOCALID_AQUACORP_GEOFF, Present_AquaCorpHQ_Movement_GeoffRushLooker
	applymovement LOCALID_AQUACORP_SARAH, Present_AquaCorpHQ_Movement_SarahRushLooker
	waitmovement 0
	speak LOCALID_AQUACORP_GEOFF, DIR_EAST, NULL, Present_AquaCorpHQ_Text_GeoffIntro
	trainerbattle_no_intro TRAINER_GRUNT_AQUA_HIDEOUT_1, Present_AquaCorpHQ_Text_GeoffDefeat
	goto Present_AquaCorpHQ_EventScript_AquaGauntletSecondTrainer
	end

@ Second grunt: TRAINER_GRUNT_AQUA_HIDEOUT_2
Present_AquaCorpHQ_EventScript_AquaGauntletSecondTrainer::
	speak LOCALID_AQUACORP_GEOFF, DIR_EAST, Name_Geoff, Present_AquaCorpHQ_Text_GeoffUnfulfilling
	speak LOCALID_AQUACORP_SARAH, DIR_WEST, NULL, Present_AquaCorpHQ_Text_SarahIntro
	trainerbattle_no_intro TRAINER_GRUNT_AQUA_HIDEOUT_2, Present_AquaCorpHQ_Text_SarahDefeat
	goto Present_AquaCorpHQ_EventScript_AquaGauntletThirdTrainer
	end

@ Third grunt: TRAINER_GRUNT_AQUA_HIDEOUT_3
Present_AquaCorpHQ_EventScript_AquaGauntletThirdTrainer::
	speak LOCALID_AQUACORP_SARAH, DIR_WEST, Name_Sarah, Present_AquaCorpHQ_Text_SarahCmonGuys
	speak LOCALID_AQUACORP_SHELDON, DIR_SOUTH, NULL, Present_AquaCorpHQ_Text_SheldonIntro
	trainerbattle_no_intro TRAINER_GRUNT_AQUA_HIDEOUT_3, Present_AquaCorpHQ_Text_SheldonDefeat
	goto Present_AquaCorpHQ_EventScript_AquaGauntletMatt
	end

Present_AquaCorpHQ_EventScript_AquaGauntletMatt::
	speak LOCALID_AQUACORP_SHELDON, DIR_SOUTH, Name_Sheldon, Present_AquaCorpHQ_Text_SheldonMyCrabs
	speak LOCALID_AQUACORP_MATT, DIR_SOUTH, Name_Matt, Present_AquaCorpHQ_Text_MattBunchOfWorthless
	closemessage
	applymovement LOCALID_AQUACORP_MATT, Present_AquaCorpHQ_MattPushSheldon
	delay 5
	playse SE_EFFECTIVE
	applymovement LOCALID_AQUACORP_SHELDON, Present_AquaCorpHQ_SheldonPushed
	waitmovement 0
	speakername Name_Sheldon
	msgbox Present_AquaCorpHQ_Text_SheldonOw, MSGBOX_DEFAULT
	speak LOCALID_AQUACORP_MATT, DIR_SOUTH, Name_Matt, Present_AquaCorp_Text_MattGottaDoItYourself
	trainerbattle_no_intro TRAINER_MATT, Present_AquaCorpHQ_Text_MattDefeat
	goto Present_AquaCorpHQ_EventScript_AquaGauntletMattDefeated
	end

Present_AquaCorpHQ_EventScript_AquaGauntletMattDefeated::
	speak LOCALID_AQUACORP_MATT, DIR_SOUTH, Name_Matt, Present_AquaCorpHQ_Text_MattAreYouKiddingMe
	speak LOCALID_AQUACORP_SHELLY, DIR_WEST, Name_Shelly, Present_AquaCorpHQ_Text_ShellyEnough
	closemessage
	playse SE_PIN
	applymovement LOCALID_AQUACORP_MATT, Common_Movement_FaceRightExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_FaceRightExclamationMark
	delay 48
	speak LOCALID_AQUACORP_SHELLY, DIR_WEST, Name_Shelly, Present_AquaCorpHQ_Text_ShellyHaventYouNoticed
	speak LOCALID_AQUACORP_MATT, DIR_EAST, Name_Matt, Present_AquaCorpHQ_Text_MattSorry
	speak LOCALID_AQUACORP_SHELLY, DIR_WEST, Name_Shelly, Present_AquaCorpHQ_Text_ShellyAndLookerYou
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, Present_AquaCorpHQ_Text_LookerSorry
	speak LOCALID_AQUACORP_SHELLY, DIR_WEST, Name_Shelly, Present_AquaCorpHQ_Text_ShellyLookerComeHere
	closemessage
	applymovement LOCALID_AQUACORP_SARAH, Present_AquaCorpHQ_Movement_SarahMoveOutOfTheWay
	applymovement LOCALID_AQUACORP_SHELLY, Present_AquaCorpHQ_Movement_ShellyWalkToLooker
	waitmovement 0
	delay 10
	speak LOCALID_AQUACORP_SHELLY, DIR_WEST, Name_Shelly, Present_AquaCorpHQ_Text_ShellyLookAtThis
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, Present_AquaCorpHQ_Text_LookerOkay
	closemessage
	applymovement LOCALID_AQUACORP_SHELLY, Present_AquaCorpHQ_Movement_ShellyWalkToWailmer
	applymovement LOCALID_PLAYER, Present_AquaCorpHQ_Movement_LookerFollowToWailmer
	waitmovement 0
	speak LOCALID_AQUACORP_SHELLY, DIR_EAST, Name_Shelly, Present_AquaCorpHQ_Text_ShellyWeAreResearchers
	speak LOCALID_AQUACORP_SARAH, DIR_SOUTH, Name_Sarah, Present_AquaCorpHQ_Text_SarahShellyDots
	closemessage
	applymovement LOCALID_AQUACORP_SARAH, Present_AquaCorpHQ_Movement_SarahWalkToShelly
	waitmovement 0
	speak LOCALID_AQUACORP_SARAH, DIR_SOUTH, Name_Sarah, Present_AquaCorpHQ_Text_SarahCanWeClamperl
	speak LOCALID_AQUACORP_SHELLY, DIR_NORTH, Name_Shelly, Present_AquaCorpHQ_Text_ShellyOfCourseWeCan
	playse SE_SELECT
	applymovement LOCALID_AQUACORP_SHELLY, Common_Movement_FaceDown
	msgbox Present_AquaCorpHQ_Text_ShellyLookerComeSeeClamperl, MSGBOX_DEFAULT
	applymovement LOCALID_AQUACORP_SHELLY, Present_AquaCorpHQ_Movement_ShellyWalkToClamperl
	applymovement LOCALID_PLAYER, Present_AquaCorpHQ_Movement_LookerFollowToClamperl
	waitmovement 0
	speak LOCALID_AQUACORP_SHELLY, DIR_SOUTH, Name_Shelly, Present_AquaCorpHQ_Text_ShellyThisClamperl
	applymovement LOCALID_AQUACORP_SHELLY, Common_Movement_FaceUp
	speak LOCALID_AQUACORP_SARAH, DIR_SOUTH, Name_Sarah, Present_AquaCorpHQ_Text_SarahClamperlIsReady
	speak LOCALID_AQUACORP_SHELLY, DIR_NORTH, Name_Shelly, Present_AquaCorpHQ_Text_ShellyGetTheDeepSeaItems
	playse SE_SELECT
	speak LOCALID_AQUACORP_SHELLY, DIR_SOUTH, Name_Shelly, Present_AquaCorpHQ_Text_ShellyThisClamperl
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_AquaCorpHQ_Text_LookerFascinating
	speak LOCALID_AQUACORP_SHELLY, DIR_SOUTH, Name_Shelly, Present_AquaCorpHQ_Text_ShellyWhichItemWouldYouWantToUse
	multichoice 0, 6, MULTI_MATT_GIVEMON, TRUE
	goto_if_eq VAR_RESULT, 0, Present_AquaCorpHQ_EventScript_ShellyGiveGorebyss
	goto_if_eq VAR_RESULT, 1, Present_AquaCorpHQ_EventScript_PhoebeGiveHuntail
	end

Present_AquaCorpHQ_EventScript_FinishAquaGauntlet::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_GOREBYSS
	removeobject LOCALID_HUNTAIL
	setvar VAR_AQUACORP_STATE, 2
	setflag FLAG_DEFEATED_MATT
	fadescreenswapbuffers FADE_TO_BLACK
	completequest QUEST_INTERROGATE_MATT
	releaseall
	end

Present_AquaCorpHQ_Movement_LookerApproachMatt1:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end
	
Present_AquaCorpHQ_Movement_FaceRightQuestionMark:
	face_right
	emote_question_mark
	step_end
	
Present_AquaCorpHQ_Movement_FaceUpQuestionMark:
	face_up
	emote_question_mark
	step_end

Present_AquaCorpHQ_Movement_WailmerScientistWalkToSee:
	walk_left
	walk_up
	walk_up
	step_end

Present_AquaCorpHQ_Movement_TableGruntMWalkToSee:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

Present_AquaCorpHQ_Movement_TableGruntFWalkToSee:
	walk_right
	walk_right
	face_up
	step_end

Present_AquaCorpHQ_Text_LookerMatt:
	.string "Aqua Admin Matt.$"

Present_AquaCorpHQ_Text_MattWhyAreYouHere:
	.string "Huh? Why are you showing your face\n"
	.string "around here?$"

Present_AquaCorpHQ_Text_LookerYoureUnderArrest:
	.string "I am taking you into custody for\n"
	.string "questioning regarding the recent\l"
	.string "downpour in Porta Bella City.\p"
	.string "Team Aqua is under suspicion for being\n"
	.string "the cause of the frenzied weather.$"

Present_AquaCorpHQ_Text_MattWhat:
	.string "… … …\n"
	.string "… … …\p"
	.string "…What did you say…?$"

Present_AquaCorpHQ_Text_LookerComeWithMe:
	.string "Matt, you're gonna have to come with\n"
	.string "me to City Hall.$"

Present_AquaCorpHQ_Text_MattDots:
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …$"

Present_AquaCorpHQ_Text_MattOhComeOn:
	.string "Oh.\p" 
	.string "Come.\p"
	.string "ON!\p"
	.string "For the last time, we are NOT\n"
	.string "doing anything seedy!\p"
	.string "Will you PLEASE get off our backs!?$"

Present_AquaCorpHQ_Text_LookerThereIsAStorm:
	.string "There is a torrential downpour outside!$"

Present_AquaCorpHQ_Text_LookerThereWasAStorm:
	.string "There was a torrential downpour outside!$"

Present_AquaCorpHQ_Text_MattSoWhatIfTheresAStorm:
	.string "So what if there's a storm outside!?\p"
	.string "We get hit with storms ALL THE TIME\n"
	.string "in Porta Bella!\p"
	.string "You can't just point at the weather\n"
	.string "and put the blame us!$"

Present_AquaCorpHQ_Text_LookerWeHaveItOnGoodIntel:
	.string "We have it on good intel that the\n"
	.string "cause of this storm is most likely\l"
	.string "the result of Tornadus and Thundurus\l"
	.string "rampaging in the absense of Landorus!$"

Present_AquaCorpHQ_Text_LookerWeHaveConfirmed:
	.string "I'll let you know, in fact, we have\n"
	.string "confirmed the storm was caused by\l"
	.string "Tornadus and Thundurus rampaging in the\l"
	.string "absense of Landorus!$"

Present_AquaCorpHQ_Text_LookerWeHaveConfirmedAreBeing:
	.string "I'll let you know, in fact, we have\n"
	.string "confirmed the storms are being caused\l"
	.string "by Tornadus and Thundurus rampaging in\l"
	.string "the absense of Landorus!$"

Present_AquaCorpHQ_Text_LookerJustThreeMonthsAgo:
	.string "Not even three months ago, your group\n"
	.string "threw the whole Hoenn region into\l"
	.string "chaos by awakening Kyogre to what…\p"
	.string "Give water Pokémon more water…?\p"
	.string "I hope you understand Team Aqua is\n"
	.string "public suspect number one right now!$"

Present_AquaCorpHQ_Text_MattGrr:
	.string "Grr…$"

Present_AquaCorpHQ_Text_ShellyWillYouJustStop:
	.string "Matt, cool it…\p"
	.string "We won't get anywhere with you getting\n"
	.string "this angry…$"

Present_AquaCorpHQ_Text_MattNoIWillNot:
	.string "Shut up, Shelly!\p"
	.string "This guy is throwing around baseless\n"
	.string "accusations! Am I wrong to be mad!?$"

Present_AquaCorpHQ_Text_MattEnoughOfThis:
	.string "Enough of this! If you won't get off\n"
	.string "our back, we'll make you!\p"
	.string "Team Aqua! Get him!$"

Present_AquaCorpHQ_Text_LookerImBack:
	.string "Matt, you are being taken into custody\n"
	.string "under suspicion of being the cause of\l"
	.string "the frenzied weather and for attacking\l"
	.string "an officer of the law.$"

Present_AquaCorpHQ_Text_MattYouWantMore:
	.string "Oh, so you want more, old man?$"

Present_AquaCorpHQ_Text_ShellyThisIsntHelping:
	.string "Matt… This isn't helping anyone…$"

Present_AquaCorpHQ_Text_MattTheGuyWontLeaveUsAlone:
	.string "Shelly, the guy won't leave us alone!$"

Present_AquaCorpHQ_Text_MattWeGottaTeachHim:
	.string "We gotta teach him the old-fashioned\n"
	.string "way not to mess with Team Aqua!\p"
	.string "Get him!$"

Present_AquaCorpHQ_Text_MattDefeat:
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "Grr…$"
	