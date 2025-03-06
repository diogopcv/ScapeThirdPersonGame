This project is a third-person game where the player must navigate a maze and find the exit. The player moves between rooms, searching for a teleporter that advances them from Level 1 to Level 2 and, ultimately, to the exit.  

The maze consists of different types of doors:  
- **Automatic doors** that open when the player approaches.  
- **Locked doors** that require specific collectibles to unlock.  

To interact with locked doors, the player must press the **"E" key**. If they possess the required collectibles, the door consumes the items from their inventory and opens. Otherwise, a UI panel displays the necessary items needed to proceed.  

The game features **six types of collectibles**, with an easily expandable system. Players can check their collected items by opening the inventory with the **"I" key**, which also closes it.  

This project is built upon the **Third-Person Character Template**. Inside the **ThirdPerson** folder, you will find:  
- **Blueprints** (for collectibles, doors, character, and teleporters)  
- **Input settings**  
- **Textures**  
- **UI elements** (UserWidgets and CustomUserWidgets)  
- **Data** (a DataTable defining collectible types)

C++ Diagram:

![Alt Text](https://raw.githubusercontent.com/diogopcv/ScapeThirdPersonGame/main/Diagram.png)
