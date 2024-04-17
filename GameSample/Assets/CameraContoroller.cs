using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class CameraContoroller : MonoBehaviour
{
    GameObject Player;
    Vector3 Playerpos;
    GameObject Camera;
    Vector3 Camerapos;
    // Update is called once per frame
    void Update()
    {
        Player = GameObject.Find("Player");
        Playerpos = Player.transform.position;
        Camera = GameObject.Find("Main Camera");
        Camerapos = Camera.transform.position;
        if(Camerapos.x < 520)
        {
        this.gameObject.transform.position = (new Vector3(Playerpos.x + 20, Playerpos.y + 5, -15));
        }
        else
        {
            this.gameObject.transform.position = new Vector3(520, Playerpos.y + 5, -15);
        }
        
    }
}
