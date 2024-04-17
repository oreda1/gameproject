using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TitlePlayer : MonoBehaviour
{

    Rigidbody2D rigid2D;
    int count;
    GameObject Player;
    Vector3 Playerpos;

    public static float playerspeed;//プレイヤーの移動速度

    void Start()
    {
        playerspeed = 20;

        this.rigid2D = GetComponent<Rigidbody2D>();
    }


    //キーを押すと、プレイヤーが移動する
    void Update()
    {
        Player = GameObject.Find("Player");
        Playerpos = Player.transform.position;
        if (this.transform.position.x > 35)
        {
            this.transform.position = new Vector3(1.9f,Playerpos.y,0);
        }

    }

    void FixedUpdate()
    {
        //移動する

        this.transform.Translate(playerspeed / 50, 0, 0);

    }
}
