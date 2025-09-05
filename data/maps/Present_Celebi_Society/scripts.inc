Present_Celebi_Society_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Present_CelebiSociety_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Present_CelebiSociety_OnFrame
	.byte 0

Present_CelebiSociety_OnTransition:
	call_if_eq VAR_PLAY_LOOKER_SCENE_ON_TRANSITION, 2, Present_CelebiSociety_PreparePostSaveEstella
	end

Present_CelebiSociety_OnFrame:
	map_script_2 VAR_PLAY_LOOKER_SCENE_ON_TRANSITION, 2, Present_CelebiSociety_PostSaveEstella
	.2byte 0

Present_CelebiSociety_PreparePostSaveEstella::
	setobjectxyperm LOCALID_CELEBISOCIETY_GRANDMA, 3, 8
	setobjectmovementtype LOCALID_CELEBISOCIETY_GRANDMA, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_PLAYER, MOVEMENT_TYPE_FACE_UP
	return

Present_CelebiSociety_PostSaveEstella::
	lockall
	applymovement LOCALID_PLAYER, Present_CelebiSociety_Movement_LookerWalkUp4
	applymovement LOCALID_CELEBISOCIETY_GRANDMA, Present_CelebiSociety_Movement_GrandmaWalkUp4
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	speak LOCALID_CELEBISOCIETY_GRANDMA, DIR_WEST, Name_Grandma, Present_CelebiSociety_Text_GrandmaDidYouMeetCelebi
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, Present_CelebiSociety_Text_LookerThatIsCorrect
	speak LOCALID_CELEBISOCIETY_GRANDMA, DIR_WEST, Name_Grandma, Present_CelebiSociety_Text_GrandmaThatIsIncredible
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, Present_CelebiSociety_Text_LookerSoYouRevere
	speak LOCALID_CELEBISOCIETY_GRANDMA, DIR_WEST, Name_Grandma, Present_CelebiSociety_Text_GrandmaIWish
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, Present_CelebiSociety_Text_LookerThankYou
	speak LOCALID_CELEBISOCIETY_GRANDMA, DIR_WEST, Name_Grandma, Present_CelebiSociety_Text_GrandmaOfCourseDearie
	closemessage
	applymovement LOCALID_CELEBISOCIETY_GRANDMA, Present_CelebiSociety_Movement_GrandmaWalkToChair
	waitmovement 0
	setobjectxyperm LOCALID_CELEBISOCIETY_GRANDMA, 8, 5
	completequest QUEST_SAVE_ESTELLA
	setvar VAR_PLAY_LOOKER_SCENE_ON_TRANSITION, 1
	clearflag FLAG_ENTER_CELEBI_SOCIETY_FROM_QUEST
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	setflag FLAG_PLAY_LOOKER_ESTELLA_ON_TRANSITION
	releaseall
	end

Present_CelebiSociety_Movement_GrandmaWalkUp4:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Present_CelebiSociety_Movement_LookerWalkUp4:
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

Present_CelebiSociety_Movement_GrandmaWalkToChair:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

Present_CelebiSociety_EventScript_Eldegoss::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ELDEGOSS, CRY_MODE_NORMAL
	msgbox Present_CelebiSociety_Text_Eldegoss, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	release
	end

Present_CelebiSociety_EventScript_MochiGiver::
	lock
	faceplayer
	call Script_GetNPCFacingDirection
	goto_if_set FLAG_SPOKE_TO_MOCHI_GIVER, Present_CelebiSociety_EventScript_MochiGiverIntroShort
	setflag FLAG_SPOKE_TO_MOCHI_GIVER
	speak LOCALID_MOCHI_MAN, VAR_0x8005, Name_Mochi_Man, Present_CelebiSociety_Text_MochiGiverIntro
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_CelebiSociety_Text_LookerNoImADetective
	speak LOCALID_MOCHI_MAN, VAR_0x8005, Name_Mochi_Man, Present_CelebiSociety_Text_MochiGiverIKnewIt
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_CelebiSociety_Text_LookerNoImNot
	speak LOCALID_MOCHI_MAN, VAR_0x8005, Name_Mochi_Man, Present_CelebiSociety_Text_MochiGiverCatchMons
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_CelebiSociety_Text_LookerImNotATrainer
	speak LOCALID_MOCHI_MAN, VAR_0x8005, Name_Mochi_Man, Present_CelebiSociety_Text_MochiGiverOffersMochi
	goto Present_CelebiSociety_EventScript_CheckForMochi
	release
	end

Present_CelebiSociety_EventScript_MochiGiverIntroShort::
	speak LOCALID_MOCHI_MAN, VAR_0x8005, Name_Mochi_Man, Present_CelebiSociety_Text_MochiGiverOffersMochiShort
	goto Present_CelebiSociety_EventScript_CheckForMochi
	end

Present_CelebiSociety_EventScript_CheckForMochi::
	clearflag FLAG_MOCHI_MAN_GAVE_MOCHI
	call_if_unset FLAG_GAVE_DEDENNE_MOCHI, Present_CelebiSociety_EventScript_CheckMochiDedenne
	call_if_unset FLAG_GAVE_TOGEDEMARU_MOCHI, Present_CelebiSociety_EventScript_CheckMochiTogedemaru
	call_if_unset FLAG_GAVE_FROSMOTH_MOCHI, Present_CelebiSociety_EventScript_CheckMochiFrosmoth
	call_if_unset FLAG_GAVE_AERODACTYL_MOCHI, Present_CelebiSociety_EventScript_CheckMochiAerodactyl
	call_if_unset FLAG_GAVE_LURANTIS_MOCHI, Present_CelebiSociety_EventScript_CheckMochiLurantis
	call_if_unset FLAG_GAVE_LUXRAY_MOCHI, Present_CelebiSociety_EventScript_CheckMochiLuxray
	call_if_unset FLAG_GAVE_WO_CHIEN_MOCHI, Present_CelebiSociety_EventScript_CheckMochiWoChien
	call_if_unset FLAG_GAVE_BEHEEYEM_MOCHI, Present_CelebiSociety_EventScript_CheckMochiBeheeyem
	call_if_unset FLAG_GAVE_TOEDSCRUEL_MOCHI, Present_CelebiSociety_EventScript_CheckMochiToedscruel
	call_if_unset FLAG_GAVE_SCREAM_TAIL_MOCHI, Present_CelebiSociety_EventScript_CheckMochiScreamTail
	call_if_unset FLAG_GAVE_KLEAVOR_MOCHI, Present_CelebiSociety_EventScript_CheckMochiKleavor
	call_if_unset FLAG_GAVE_GOODRA_HISUI_MOCHI, Present_CelebiSociety_EventScript_CheckMochiGoodraHisui
	call_if_unset FLAG_GAVE_LUXRAY_DARK_MOCHI, Present_CelebiSociety_EventScript_CheckMochiLuxrayDark
	call_if_unset FLAG_GAVE_TORNADUS_MOCHI, Present_CelebiSociety_EventScript_CheckMochiTornadus
	call_if_unset FLAG_GAVE_THUNDURUS_MOCHI, Present_CelebiSociety_EventScript_CheckMochiThundurus
	call_if_set FLAG_MOCHI_MAN_GAVE_MOCHI, Present_CelebiSociety_EventScript_LookerReceivedMochi
	call_if_unset FLAG_MOCHI_MAN_GAVE_MOCHI, Present_CelebiSociety_EventScript_NoNewPokemon
	closemessage
	release
	end

Present_CelebiSociety_EventScript_LookerReceivedMochi::
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	message Looker_Text_Mochi
	delay 10
	waitfanfare
	speak LOCALID_MOCHI_MAN, VAR_0x8005, Name_Mochi_Man, Present_CelebiSociety_Text_MochiManLetMeKnow
	return

Present_CelebiSociety_EventScript_NoNewPokemon::
	speak LOCALID_MOCHI_MAN, VAR_0x8005, Name_Mochi_Man, Present_CelebiSociety_Text_MochiManNoNewPokemon
	return

Present_CelebiSociety_EventScript_CheckMochiDedenne::
	call_if_set FLAG_CHOSE_DEDENNE, Present_CelebiSociety_EventScript_CheckMochiDedenne2
	return

Present_CelebiSociety_EventScript_CheckMochiDedenne2::
	call_if_set FLAG_CAUGHT_RODENT, Present_CelebiSociety_EventScript_GiveMochiDedenne
	return

Present_CelebiSociety_EventScript_GiveMochiDedenne::
	bufferspeciesname STR_VAR_1, SPECIES_DEDENNE
	speak LOCALID_MOCHI_MAN, VAR_0x8005, Name_Mochi_Man, Present_CelebiSociety_Text_MochiManOhPokemon
	additem ITEM_SPATK_MOCHI, 1
	additem ITEM_SPDEF_MOCHI, 2
	additem ITEM_SPE_MOCHI, 1
	setflag FLAG_MOCHI_MAN_GAVE_MOCHI
	setflag FLAG_GAVE_DEDENNE_MOCHI
	return

Present_CelebiSociety_EventScript_CheckMochiTogedemaru::
	call_if_set FLAG_CHOSE_TOGEDEMARU, Present_CelebiSociety_EventScript_CheckMochiTogedemaru2
	return

Present_CelebiSociety_EventScript_CheckMochiTogedemaru2::
	call_if_set FLAG_CAUGHT_RODENT, Present_CelebiSociety_EventScript_GiveMochiTogedemaru
	return

Present_CelebiSociety_EventScript_GiveMochiTogedemaru::
	bufferspeciesname STR_VAR_1, SPECIES_TOGEDEMARU
	speak LOCALID_MOCHI_MAN, VAR_0x8005, Name_Mochi_Man, Present_CelebiSociety_Text_MochiManOhPokemon
	additem ITEM_ATK_MOCHI, 1
	additem ITEM_DEF_MOCHI, 2
	additem ITEM_SPE_MOCHI, 1
	setflag FLAG_MOCHI_MAN_GAVE_MOCHI
	setflag FLAG_GAVE_TOGEDEMARU_MOCHI
	return

Present_CelebiSociety_EventScript_CheckMochiFrosmoth::
	call_if_set FLAG_CAUGHT_FROSMOTH, Present_CelebiSociety_EventScript_GiveMochiFrosmoth
	return

Present_CelebiSociety_EventScript_GiveMochiFrosmoth::
	bufferspeciesname STR_VAR_1, SPECIES_FROSMOTH
	speak LOCALID_MOCHI_MAN, VAR_0x8005, Name_Mochi_Man, Present_CelebiSociety_Text_MochiManOhPokemon
	additem ITEM_SPATK_MOCHI, 2
	additem ITEM_SPDEF_MOCHI, 2
	setflag FLAG_MOCHI_MAN_GAVE_MOCHI
	setflag FLAG_GAVE_FROSMOTH_MOCHI
	return

Present_CelebiSociety_EventScript_CheckMochiAerodactyl::
	call_if_set FLAG_CAUGHT_AERODACTYL, Present_CelebiSociety_EventScript_GiveMochiAerodactul
	return

Present_CelebiSociety_EventScript_GiveMochiAerodactul::
	bufferspeciesname STR_VAR_1, SPECIES_AERODACTYL
	speak LOCALID_MOCHI_MAN, VAR_0x8005, Name_Mochi_Man, Present_CelebiSociety_Text_MochiManOhAerodactyl
	additem ITEM_ATK_MOCHI, 1
	additem ITEM_DEF_MOCHI, 1
	additem ITEM_SPE_MOCHI, 2
	setflag FLAG_MOCHI_MAN_GAVE_MOCHI
	setflag FLAG_GAVE_AERODACTYL_MOCHI
	return

Present_CelebiSociety_EventScript_CheckMochiLurantis::
	call_if_set FLAG_CAUGHT_LURANTIS, Present_CelebiSociety_EventScript_GiveMochiLurantis
	return

Present_CelebiSociety_EventScript_GiveMochiLurantis::
	bufferspeciesname STR_VAR_1, SPECIES_LURANTIS
	speak LOCALID_MOCHI_MAN, VAR_0x8005, Name_Mochi_Man, Present_CelebiSociety_Text_MochiManOhPokemon
	additem ITEM_HP_MOCHI, 1
	additem ITEM_ATK_MOCHI, 2
	additem ITEM_DEF_MOCHI, 1
	setflag FLAG_MOCHI_MAN_GAVE_MOCHI
	setflag FLAG_GAVE_LURANTIS_MOCHI
	return

Present_CelebiSociety_EventScript_CheckMochiLuxray::
	call_if_set FLAG_CAUGHT_LUXRAY, Present_CelebiSociety_EventScript_GiveMochiLuxray
	return

Present_CelebiSociety_EventScript_GiveMochiLuxray::
	bufferspeciesname STR_VAR_1, SPECIES_LUXRAY
	speak LOCALID_MOCHI_MAN, VAR_0x8005, Name_Mochi_Man, Present_CelebiSociety_Text_MochiManOhPokemon
	additem ITEM_HP_MOCHI, 1
	additem ITEM_ATK_MOCHI, 1
	additem ITEM_DEF_MOCHI, 1
	additem ITEM_SPE_MOCHI, 1
	setflag FLAG_MOCHI_MAN_GAVE_MOCHI
	setflag FLAG_GAVE_LUXRAY_MOCHI
	return

Present_CelebiSociety_EventScript_CheckMochiWoChien::
	call_if_set FLAG_CAUGHT_WO_CHIEN, Present_CelebiSociety_EventScript_GiveMochiWoChien
	return

Present_CelebiSociety_EventScript_GiveMochiWoChien::
	bufferspeciesname STR_VAR_1, SPECIES_WO_CHIEN
	speak LOCALID_MOCHI_MAN, VAR_0x8005, Name_Mochi_Man, Present_CelebiSociety_Text_MochiManOhLegendary
	additem ITEM_DEF_MOCHI, 2
	additem ITEM_SPDEF_MOCHI, 2
	setflag FLAG_MOCHI_MAN_GAVE_MOCHI
	setflag FLAG_GAVE_WO_CHIEN_MOCHI
	return

Present_CelebiSociety_EventScript_CheckMochiBeheeyem::
	call_if_set FLAG_CAUGHT_BEHEEYEM, Present_CelebiSociety_EventScript_GiveMochiBeheeyem
	return

Present_CelebiSociety_EventScript_GiveMochiBeheeyem::
	bufferspeciesname STR_VAR_1, SPECIES_BEHEEYEM
	speak LOCALID_MOCHI_MAN, VAR_0x8005, Name_Mochi_Man, Present_CelebiSociety_Text_MochiManOhPokemon
	additem ITEM_DEF_MOCHI, 1
	additem ITEM_SPATK_MOCHI, 2
	additem ITEM_SPDEF_MOCHI, 1
	setflag FLAG_MOCHI_MAN_GAVE_MOCHI
	setflag FLAG_GAVE_BEHEEYEM_MOCHI
	return

Present_CelebiSociety_EventScript_CheckMochiToedscruel::
	call_if_set FLAG_CAUGHT_TOEDSCRUEL, Present_CelebiSociety_EventScript_GiveMochiToedscruel
	return

Present_CelebiSociety_EventScript_GiveMochiToedscruel::
	bufferspeciesname STR_VAR_1, SPECIES_TOEDSCRUEL
	speak LOCALID_MOCHI_MAN, VAR_0x8005, Name_Mochi_Man, Present_CelebiSociety_Text_MochiManOhPokemon
	additem ITEM_HP_MOCHI, 1
	additem ITEM_SPATK_MOCHI, 1
	additem ITEM_SPDEF_MOCHI, 2
	setflag FLAG_MOCHI_MAN_GAVE_MOCHI
	setflag FLAG_GAVE_TOEDSCRUEL_MOCHI
	return

Present_CelebiSociety_EventScript_CheckMochiScreamTail::
	call_if_set FLAG_CAUGHT_SCREAM_TAIL, Present_CelebiSociety_EventScript_GiveMochiScreamTail
	return

Present_CelebiSociety_EventScript_GiveMochiScreamTail::
	bufferspeciesname STR_VAR_1, SPECIES_SCREAM_TAIL
	speak LOCALID_MOCHI_MAN, VAR_0x8005, Name_Mochi_Man, Present_CelebiSociety_Text_MochiManOhScreamTail
	additem ITEM_HP_MOCHI, 1
	additem ITEM_DEF_MOCHI, 1
	additem ITEM_SPDEF_MOCHI, 1
	additem ITEM_SPE_MOCHI, 1
	setflag FLAG_MOCHI_MAN_GAVE_MOCHI
	setflag FLAG_GAVE_SCREAM_TAIL_MOCHI
	return

Present_CelebiSociety_EventScript_CheckMochiKleavor::
	call_if_set FLAG_CAUGHT_KLEAVOR, Present_CelebiSociety_EventScript_GiveMochiKleavor
	return

Present_CelebiSociety_EventScript_GiveMochiKleavor::
	bufferspeciesname STR_VAR_1, SPECIES_KLEAVOR
	speak LOCALID_MOCHI_MAN, VAR_0x8005, Name_Mochi_Man, Present_CelebiSociety_Text_MochiManOhPokemon
	additem ITEM_HP_MOCHI, 1
	additem ITEM_ATK_MOCHI, 1
	additem ITEM_DEF_MOCHI, 2
	setflag FLAG_MOCHI_MAN_GAVE_MOCHI
	setflag FLAG_GAVE_KLEAVOR_MOCHI
	return

Present_CelebiSociety_EventScript_CheckMochiGoodraHisui::
	call_if_set FLAG_CAUGHT_GOODRA_HISUI, Present_CelebiSociety_EventScript_GiveMochiGoodraHisui
	return

Present_CelebiSociety_EventScript_GiveMochiGoodraHisui::
	bufferspeciesname STR_VAR_1, SPECIES_GOODRA_HISUI
	speak LOCALID_MOCHI_MAN, VAR_0x8005, Name_Mochi_Man, Present_CelebiSociety_Text_MochiManOhPokemon
	additem ITEM_ATK_MOCHI, 1
	additem ITEM_DEF_MOCHI, 2
	additem ITEM_SPDEF_MOCHI, 1
	setflag FLAG_MOCHI_MAN_GAVE_MOCHI
	setflag FLAG_GAVE_GOODRA_HISUI_MOCHI
	return

Present_CelebiSociety_EventScript_CheckMochiLuxrayDark::
	call_if_set FLAG_CAUGHT_LUXRAY_DARK, Present_CelebiSociety_EventScript_GiveMochiLuxrayDark
	return

Present_CelebiSociety_EventScript_GiveMochiLuxrayDark::
	bufferspeciesname STR_VAR_1, SPECIES_LUXRAY_DARK
	speak LOCALID_MOCHI_MAN, VAR_0x8005, Name_Mochi_Man, Present_CelebiSociety_Text_MochiManOhDarkLuxray
	additem ITEM_HP_MOCHI, 1
	additem ITEM_ATK_MOCHI, 2
	additem ITEM_SPE_MOCHI, 1
	setflag FLAG_MOCHI_MAN_GAVE_MOCHI
	setflag FLAG_GAVE_LUXRAY_DARK_MOCHI
	return

Present_CelebiSociety_EventScript_CheckMochiTornadus::
	call_if_set FLAG_CAUGHT_TORNADUS, Present_CelebiSociety_EventScript_GiveMochiTornadus
	return

Present_CelebiSociety_EventScript_GiveMochiTornadus::
	bufferspeciesname STR_VAR_1, SPECIES_TORNADUS
	speak LOCALID_MOCHI_MAN, VAR_0x8005, Name_Mochi_Man, Present_CelebiSociety_Text_MochiManOhLegendary
	additem ITEM_ATK_MOCHI, 1
	additem ITEM_SPATK_MOCHI, 1
	additem ITEM_SPE_MOCHI, 2
	setflag FLAG_MOCHI_MAN_GAVE_MOCHI
	setflag FLAG_GAVE_TORNADUS_MOCHI
	return

Present_CelebiSociety_EventScript_CheckMochiThundurus::
	call_if_set FLAG_CAUGHT_THUNDURUS, Present_CelebiSociety_EventScript_GiveMochiThundurus
	return

Present_CelebiSociety_EventScript_GiveMochiThundurus::
	bufferspeciesname STR_VAR_1, SPECIES_THUNDURUS
	speak LOCALID_MOCHI_MAN, VAR_0x8005, Name_Mochi_Man, Present_CelebiSociety_Text_MochiManOhLegendary
	additem ITEM_ATK_MOCHI, 1
	additem ITEM_SPATK_MOCHI, 2
	additem ITEM_SPE_MOCHI, 1
	setflag FLAG_MOCHI_MAN_GAVE_MOCHI
	setflag FLAG_GAVE_THUNDURUS_MOCHI
	return

Present_CelebiSociety_EventScript_MochiResetter::
	lockall
	faceplayer
	speakername Name_Old_Lady
	call_if_unset FLAG_SPOKE_TO_MOCHI_RESETTER, Present_CelebiSociety_EventScript_MochiResetterFirstTime
	setflag FLAG_SPOKE_TO_MOCHI_RESETTER
	clearflag FLAG_MOCHI_MAN_GAVE_MOCHI
	msgbox Present_CelebiSociety_Text_MochiResetterCanResetEVs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Present_CelebiSociety_EventScript_MochiResetterEnd
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Present_CelebiSociety_EventScript_MochiResetterEnd
	specialvar VAR_RESULT, GetMochi
	goto_if_eq VAR_RESULT, FALSE, Present_CelebiSociety_EventScript_MochiResetterAlreadyEmpty
	call_if_ne VAR_TEMP_A, 0, Present_CelebiSociety_EventScript_MochiResetterHP
	call_if_ne VAR_TEMP_B, 0, Present_CelebiSociety_EventScript_MochiResetterAtk
	call_if_ne VAR_TEMP_C, 0, Present_CelebiSociety_EventScript_MochiResetterDef
	call_if_ne VAR_TEMP_D, 0, Present_CelebiSociety_EventScript_MochiResetterSpeed
	call_if_ne VAR_TEMP_E, 0, Present_CelebiSociety_EventScript_MochiResetterSpAtk
	call_if_ne VAR_TEMP_F, 0, Present_CelebiSociety_EventScript_MochiResetterSpDef
	special BufferMoveDeleterNicknameAndMove
	speakername NULL
	playfanfare MUS_MOVE_DELETED
	message Present_CelebiSociety_Text_EmptiedBelly
	waitmessage
	waitfanfare
	delay 10
	msgbox Looker_Text_AlsoMochi, MSGBOX_DEFAULT
	goto Present_CelebiSociety_EventScript_MochiResetterEnd
	end

Present_CelebiSociety_EventScript_MochiResetterHP::
	additem ITEM_HP_MOCHI, VAR_TEMP_A
	return

Present_CelebiSociety_EventScript_MochiResetterAtk::
	additem ITEM_ATK_MOCHI, VAR_TEMP_B
	return

Present_CelebiSociety_EventScript_MochiResetterDef::
	additem ITEM_DEF_MOCHI, VAR_TEMP_C
	return
	
Present_CelebiSociety_EventScript_MochiResetterSpeed::
	additem ITEM_SPE_MOCHI, VAR_TEMP_D
	return
	
Present_CelebiSociety_EventScript_MochiResetterSpAtk::
	additem ITEM_SPATK_MOCHI, VAR_TEMP_E
	return
	
Present_CelebiSociety_EventScript_MochiResetterSpDef::
	additem ITEM_SPDEF_MOCHI, VAR_TEMP_F
	return

Present_CelebiSociety_EventScript_MochiResetterFirstTime::
	msgbox Present_CelebiSociety_Text_MochiResetterIntro, MSGBOX_DEFAULT
	playse SE_SELECT
	return

Present_CelebiSociety_EventScript_MochiResetterEnd::
	speakername Name_Old_Lady
	msgbox Present_CelebiSociety_Text_MochiResetterEnd, MSGBOX_DEFAULT
	closemessage
	releaseall
	end
	
Present_CelebiSociety_EventScript_MochiResetterAlreadyEmpty::
	special BufferMoveDeleterNicknameAndMove
	speakername Name_Old_Lady
	msgbox Present_CelebiSociety_Text_MochiResetterAlreadyEmpty, MSGBOX_DEFAULT
	closemessage
	releaseall
	end
	
Present_CelebiSociety_EventScript_Grandma::
	speakername Name_Grandma
	msgbox Present_CelebiSociety_Text_Grandma, MSGBOX_NPC
	end

Present_CelebiSociety_Text_Grandma:
	.string "Long ago, I had a run-in with Celebi\n"
	.string "myself!\p"
	.string "I was cornered by a devious-looking wild\n"
	.string "Luxray when she came to my rescue!\p"
	.string "Let me tell you, I was nauseous for a\n"
	.string "full week after that!\p"
	.string "Sending me through time DID cause me to\n"
	.string "see the future here and there for a few\l"
	.string "days afterward…\p"
	.string "Wheeehehehe! That's how I met my husband!\n"
	.string "Have you experienced it?$"
	
Present_CelebiSociety_Text_MochiResetterIntro:
	.string "Oh, that silly old man there is always\n"
	.string "giving away handfuls of MOCHI!\p"
	.string "It can make your poor POKéMONs'\n"
	.string "bellies ache if you eat too much…\p"
	.string "Say, if you ever feed your POKéMON\n"
	.string "too much MOCHI and want their bellies\l"
	.string "emptied, let me know.\p"
	.string "I can even give you more MOCHI after!\p"
	.string "… … …Oh?\p"
	.string "You want to know HOW I empty your\n"
	.string "POKéMONs' bellies of MOCHI?\p"
	.string "Don't ask.$"

Present_CelebiSociety_Text_MochiResetterCanResetEVs:
	.string "Would you like me to empty your\n"
	.string "POKéMON's belly of MOCHI?$"

Present_CelebiSociety_Text_MochiResetterWhichPokemon:
	.string "Nweeheehee… Which POKéMON will I\n"
	.string "empty the belly of today?$"

Present_CelebiSociety_Text_MochiResetterEnd:
	.string "If you ever want your POKéMONs'\n"
	.string "bellies emptied, you know the lady\l"
	.string "with that special touch!$"

Present_CelebiSociety_Text_MochiResetterAlreadyEmpty:
	.string "What!? Your {STR_VAR_1}'s belly is\n"
	.string "already empty!\p"
	.string "Please don't toy with an old lady!$"

Present_CelebiSociety_Text_EmptiedBelly:
	.string "{STR_VAR_1}'s belly was emptied…!$"

Present_CelebiSociety_Text_MochiGiverIntro:
	.string "Eeeheeheeheeheehee!\p"
	.string "Say, you look like a young snapper!\p"
	.string "Tell me, are you taking the GYM\n"
	.string "challenge?$"

Present_CelebiSociety_Text_LookerNoImADetective:
	.string "No sir. I'm a detective with the\n"
	.string "International Po-$"

Present_CelebiSociety_Text_MochiGiverIKnewIt:
	.string "Eeeheeheeheehee! I knew it!\p"
	.string "Tell me, how many GYMs have you taken\n"
	.string "down by now?\p"
	.string "PORTA BELLA's GYM leader is one of the\n"
	.string "best around, you know!\p"
	.string "She's one of the best trainers in Hoenn!$"

Present_CelebiSociety_Text_LookerNoImNot:
	.string "I have not taken the gym challenge in\n"
	.string "20 years, sir.$"
	
Present_CelebiSociety_Text_MochiGiverCatchMons:
	.string "Oh, I bet!\n"
	.string "Tell me, do you like catching POKéMON?\p"
	.string "The POKéMON in the forest are quite a\n"
	.string "powerful lot!\p"
	.string "When I was but a boy, I got scooped up\n"
	.string "by what looked like a pterodactyl!\p"
	.string "Oh, that silly Celebi LOVES bringing in\n"
	.string "all kinds of POKéMON from across time!$"

Present_CelebiSociety_Text_LookerImNotATrainer:
	.string "That sounds terrifying. But no, I don't\n"
	.string "tend to catch many Po-$"

Present_CelebiSociety_Text_MochiGiverOffersMochi:
	.string "If you ever catch an interesting\n"
	.string "POKéMON, I would love it if you told me\l"
	.string "the story of your encounter!\p"
	.string "In fact, I can offer you some sweet\n"
	.string "MOCHI in return!\p"
	.string "I tell you, it's DEEEEELISH!$"

Present_CelebiSociety_Text_MochiGiverOffersMochiShort:
	.string "If you ever catch an interesting\n"
	.string "POKéMON, I would love it if you told me\l"
	.string "the story of your encounter!$"

Present_CelebiSociety_Text_MochiManOhPokemon:
	.string "Oh? You caught a {STR_VAR_1}?\n"
	.string "Eeeheeehee! Here, have some MOCHI!$"

Present_CelebiSociety_Text_MochiManOhDarkLuxray:
	.string "Oh? You caught a dark {STR_VAR_1}?\n"
	.string "Eeeheehee! I didn't know such a\l"
	.string "POKéMON even existed!\p"
	.string "Here, have some MOCHI!$"

Present_CelebiSociety_Text_MochiManOhAerodactyl:
	.string "Oh? You caught a {STR_VAR_1}?\n"
	.string "Eeeheeehee! Maybe it's the one who\l"
	.string "yoinked me as a wee child! Who knows!\p" 
	.string "Here, have some MOCHI!$"

Present_CelebiSociety_Text_MochiManOhScreamTail:
	.string "Oh? You caught a {STR_VAR_1}?\n"
	.string "Eeeheeehee! I've never even heard\l"
	.string "of that POKéMON!\p"
	.string "Here, have some MOCHI!$"

Present_CelebiSociety_Text_MochiManOhLegendary:
	.string "Wow! Incredible!\n"
	.string "You caught {STR_VAR_1}?\p"
	.string "What a talented young man you are!\p"
	.string "Have some MOCHI!$"

Present_CelebiSociety_Text_MochiManLetMeKnow:
	.string "Eeeheeehee! If you find any more\n"
	.string "interesting POKéMON, let me know!$"

Present_CelebiSociety_Text_MochiManNoNewPokemon:
	.string "Oh? You don't have any new stories of\n"
	.string "your POKéMON-catching escapades?\p"
	.string "What a shame.$"
	
Present_CelebiSociety_Text_GrandmaDidYouMeetCelebi:
	.string "Here we are.\p"
	.string "To continue our conversation,\n"
	.string "did you truly meet Celebi?$"

Present_CelebiSociety_Text_LookerThatIsCorrect:
	.string "That is correct. We were sent to the\n"
	.string "past after being surrounded by a\l"
	.string "horde of wild Pokémon.$"

Present_CelebiSociety_Text_GrandmaThatIsIncredible:
	.string "How incredible…\p"
	.string "We here at the Celebi Society meet\n"
	.string "every month to clear the weeds and\l"
	.string "maintain the shrines.\p"
	.string "To think, Celebi is still out there…\p"
	.string "Such a thought brings peace to my soul.$"

Present_CelebiSociety_Text_LookerSoYouRevere:
	.string "So you in the city revere Celebi and\n"
	.string "Landorus, even to this day?$"

Present_CelebiSociety_Text_GrandmaIWish:
	.string "I wish that were the case.\p"
	.string "When the city became a major port, its\n"
	.string "people let go of the traditions set\l"
	.string "at Porta Bella's founding.\p"
	.string "We still maintain the oral traditions,\n"
	.string "but many of us are getting old…\p"
	.string "Only locals know of the importance of\n"
	.string "the spirits of Peace and Prosperity,\l"
	.string "but even still…\p"
	.string "Very few people have reverence for\n"
	.string "the spirits who gave Porta Bella its\l"
	.string "peaceful skies and fertile land…\p"
	.string "We fear these stories will die with\n"
	.string "us, only written in books as fables…$"

Present_CelebiSociety_Text_LookerThankYou:
	.string "Hmm…\p"
	.string "Thank you for sharing. I will need\n"
	.string "to think on this.$"

Present_CelebiSociety_Text_GrandmaOfCourseDearie:
	.string "Of course, dearie.\p"
	.string "If you would ever like to know more,\n"
	.string "I will gladly share what I've learned.$"

Present_CelebiSociety_Text_Eldegoss:
	.string "Fwooooooo!$"