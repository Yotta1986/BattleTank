 ![Banner](/BattleTank/Pictures/Banner.jpg)

# Battle Tank

This is a game about... Oh, this is not a game yet.

It's started because I have took the [course](https://www.udemy.com/unrealcourse/). 

Now, in this version, player can drive a tank which looks powerful but actually weak, to fight with other tens of AI tank with crazy movement and high accuracy.



## Development

* Version: [Unreal Engine 4]([https://www.unrealengine.com/](http://www.baidu.com/link?url=aaoWkzwdoF7Gr-RfER1k3bDxNWeCMEV7nWS9vRP76yVv-9piIoD0aR12udmVxYrF)).15
* Platform: i5 4460 + GTX970, i5 6600 + RX480


* Developing rules:
  * Blueprint handles all of UI, asset initialization  
  * New feature should be tested in Blueprint first
  * Pointer should be well protected and checked before used
  * Cpp handles most of game logic




## Class

* Main Cpp classes relations:
  * Cpp class AIController and PlayerController are both inherited from Controller. They handle their input respectively.
  * Cpp class AimComponent and MovementComponent are both inherited from ActorComponent. AimComponent handles aiming and firing, MovementComponent handles movement.
  * AimComponent has three members (pointers), Turret, Barrel and Projectile. 
  * Turret and Barrel  is unique for one Tank. They provide aiming action. 
  * Projectile TODO

![ClassRelations](/BattleTank/Pictures/ClassRelations.png)

* Main blueprint classes relations:

  ![Tank_BP](/BattleTank/Pictures/Tank_BP.png)

![Projectile_BP](/BattleTank/Pictures/Projectile_BP.png)

![Mortar_BP](/BattleTank/Pictures/Mortar_BP.png)

## To Do list

* Divide camp, with different UI, with camp damage
* Flexible and changeable AI setting(projectile damage, reload time) , Flexible way for AI to choose an enemy
* Better UI
* More kinds of Attacking ways
* More kinds of AI Pawn (new combination of components)
* New attack way (fire component maybe? )




## Doing

  * Camp damage

* A better way to spawn AI Tank and AI Controller.

  * ~~Spawn in blueprint~~
  * ~~Make an Actor, a Spawner~~
  * Move logic to Cpp

* And garbage collection, to collect dead Controller and Tank

  * Implement in Blueprint
  * Move logic to Cpp









## Screenshots

![](/BattleTank/Pictures/Game.png)

![](/BattleTank/Pictures/Game5.png)

![](/BattleTank/Pictures/Game6.png)

![](/BattleTank/Pictures/Game7.png)