 // © 2025 Marco Fernandez garcia <marcoferciatr@gmail.com>


#include "DataAssets/EnemyBuilderDataAsset.h"


bool UEnemyBuilderDataAsset::CheckInformationFilled() const
{
  if (!EnemyMesh)
  {
    return false;
  }

  if (!GameplayEffectClass)
  {
   return false;
  }

  if (!HealthBarWidgetClass)
  {
   return false;
  }

 if (!StateTreeSchema.IsValid())
 {
   return false;
 }

 if (!AbilitiesDataAsset)
 {
  return false;
 }
  
 
  return true;
 }
