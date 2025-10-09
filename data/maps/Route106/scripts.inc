Route106_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route106_OnTransition
	.byte 0

Route106_OnTransition:
	call_if_ne VAR_BRINEY_LOCATION, 4, Route106_Hide_Briney
	call_if_eq VAR_BRINEY_LOCATION, 4, Route106_Show_Briney
	end

Route106_Hide_Briney::
	setflag FLAG_HIDE_ROUTE_106_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_106_MR_BRINEY_BOAT
	end

Route106_Show_Briney::
	clearflag FLAG_HIDE_ROUTE_106_MR_BRINEY
    clearflag FLAG_HIDE_ROUTE_106_MR_BRINEY_BOAT
    end

Route106_EventScript_TrainerTipsSign::
	msgbox Route106_Text_TrainerTips, MSGBOX_SIGN
	end

Route106_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS, Route106_Text_DouglasIntro, Route106_Text_DouglasDefeated
	msgbox Route106_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Kyla::
	trainerbattle_single TRAINER_KYLA, Route106_Text_KylaIntro, Route106_Text_KylaDefeated
	msgbox Route106_Text_KylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Elliot::
	trainerbattle_single TRAINER_ELLIOT_1, Route106_Text_ElliotIntro, Route106_Text_ElliotDefeated, Route106_EventScript_ElliotRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route106_EventScript_ElliotRematch
	msgbox Route106_Text_ElliotPostBattle, MSGBOX_DEFAULT
	release
	end

Route106_EventScript_ElliotRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route106_Text_ElliotRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ELLIOT_1
	release
	end

Route106_EventScript_ElliotRematch::
	trainerbattle_rematch TRAINER_ELLIOT_1, Route106_Text_ElliotRematchIntro, Route106_Text_ElliotRematchDefeated
	msgbox Route106_Text_ElliotRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Ned::
	trainerbattle_single TRAINER_NED, Route106_Text_NedIntro, Route106_Text_NedDefeated
	msgbox Route106_Text_NedPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_Text_TrainerTips:
	.string "Trainer Tips\p"
	.string "Advice on catching Pokémon with a Rod:\n"
	.string "Press the A Button if you get a bite.$"

Route106_EventScript_LittlerootWoodsSign::
	msgbox Route106_Text_LittlerootWoodsSign, MSGBOX_SIGN
	end

Route106_Text_LittlerootWoodsSign:
	.string "North to Littleroot Woods.\n"
	.string "A charming forest, home to many Pokémon.$"

Route106_EventScript_Briney::
	lockall
    faceplayer
    message Route106_Text_BackToDewford
    waitmessage
    multichoicedefault 21, 6, MULTI_YESNO, 0, FALSE
    switch VAR_RESULT
    case 0, Route106_EventScript_Yes
    case 1, Route106_EventScript_CancelSailSelect
    case MULTI_B_PRESSED, Route106_EventScript_CancelSailSelect
	releaseall
    end

Route106_Text_BackToDewford:
	.string "Mr. Briney: So you want to be heading\n"
	.string "back to Dewford Town?$"

Route106_EventScript_Yes::
	msgbox Route106_Text_Briney_DewfordSettingSail, MSGBOX_DEFAULT
	closemessage
	goto Route106_EventScript_SailToDewford
	release
	end

Route106_EventScript_SailToDewford::
	lockall
	call EventScript_BackupMrBrineyLocation
	setobjectsubpriority LOCALID_ROUTE106_BRINEY, MAP_ROUTE106, 0
	setobjectsubpriority LOCALID_PLAYER, MAP_ROUTE106, 0
	setobjectsubpriority LOCALID_ROUTE106_BOAT, MAP_ROUTE106, 1
	applymovement LOCALID_ROUTE106_BRINEY, Route106_Movement_BrineyBoardBoat
	waitmovement 0
	removeobject LOCALID_ROUTE106_BRINEY
	applymovement LOCALID_PLAYER, Route106_Movement_PlayerBoardBoat
	waitmovement 0
	hideobjectat LOCALID_PLAYER, MAP_ROUTE106
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement LOCALID_ROUTE106_BOAT, Route106_Movement_SailToDewford
	applymovement LOCALID_PLAYER, Route106_Movement_SailToDewford
	waitmovement 0
    clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
    showobjectat LOCALID_DEWFORD_BOAT, MAP_DEWFORD_TOWN
	setobjectsubpriority LOCALID_DEWFORD_BOAT, MAP_DEWFORD_TOWN, 1
	showobjectat LOCALID_PLAYER, MAP_DEWFORD_TOWN
	call Common_EventScript_StopBrineysBoatMusic
	applymovement LOCALID_PLAYER, Route106_Movement_ExitBoatDewford
	waitmovement LOCALID_PLAYER, MAP_DEWFORD_TOWN
	setobjectxyperm LOCALID_DEWFORD_BRINEY, 22, 8
	addobject LOCALID_DEWFORD_BRINEY
	setobjectsubpriority LOCALID_DEWFORD_BRINEY, MAP_DEWFORD_TOWN, 0
	applymovement LOCALID_DEWFORD_BRINEY, Route106_Movement_BrineyExitBoat_Dewford
	waitmovement 0
	clearflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	hideobjectat LOCALID_ROUTE106_BOAT, MAP_ROUTE106
	setvar VAR_BRINEY_LOCATION, 2
	call EventScript_ResetMrBriney
	resetobjectsubpriority LOCALID_PLAYER, MAP_DEWFORD_TOWN
	releaseall
	end

Route106_Text_Briney_DewfordSettingSail:
    .string "Mr. Briney: Aye aye!\n"
    .string "We're setting sail for Dewford!$"

Route106_Movement_SailToDewford::
	walk_down
	walk_down
	walk_fast_down
	walk_fast_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_down
	walk_down
	step_end
	releaseall
	end

Route106_Movement_BrineyBoardBoat:
	walk_down
	walk_down
    step_end

Route106_Movement_PlayerBoardBoat:
    walk_left
    walk_down
	walk_down
    step_end

Route106_Movement_ExitBoatDewford:
	walk_down
	walk_left
	step_end

Route106_Movement_BrineyExitBoat_Dewford:
	walk_down
    face_left
	step_end

Route106_EventScript_CancelSailSelect::
	msgbox Route106_Text_JustTellMeWhenYouNeedToSetSail, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Route106_Text_JustTellMeWhenYouNeedToSetSail:
	.string "Mr. Briney: You just tell me whenever\n"
	.string "you need to set sail again!$"

