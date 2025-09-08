// TFDNativeGameplayTags.cpp
#include "TFDNativeGameplayTags.h"
//1. 팀 구분 경찰/도둑/중립
UE_DEFINE_GAMEPLAY_TAG(TAG_Team_Cop, "Team.Cop");
UE_DEFINE_GAMEPLAY_TAG(TAG_Team_Thief, "Team.Thief");
UE_DEFINE_GAMEPLAY_TAG(TAG_Team_Neutral, "Team.Neutral");

//2.캐릭터 상태
UE_DEFINE_GAMEPLAY_TAG(TAG_Character_State_Arrested, "Character.State.Arrested");
UE_DEFINE_GAMEPLAY_TAG(TAG_Character_State_Hiding, "Character.State.Hiding");
UE_DEFINE_GAMEPLAY_TAG(TAG_Character_State_Idle, "Character.State.Idle");
UE_DEFINE_GAMEPLAY_TAG(TAG_Character_State_Stun, "Character.State.Stun");
UE_DEFINE_GAMEPLAY_TAG(TAG_Character_State_Detecting, "Character.State.Detecting");

//3.캐릭터 능력 
UE_DEFINE_GAMEPLAY_TAG(TAG_Ability_Cop_Handcuff, "Ability.Cop.Handcuff");
UE_DEFINE_GAMEPLAY_TAG(TAG_Ability_Thief_Steal, "Ability.Thief.Steal");

//4. object
UE_DEFINE_GAMEPLAY_TAG(TAG_Object_Door,"Object.Door"); //문
UE_DEFINE_GAMEPLAY_TAG(TAG_Object_Money,"Object.Money"); //돈

//5.게임플레이큐 - 이펙트
UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayCue_Arrested, "GameplayCue.Arrested");
