using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ClearPlayer : MonoBehaviour
{
    float Speed;
    Vector3 Playerpos;
    // Start is called before the first frame update
    void Start()
    {
        Speed = 10;
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        this.transform.Translate(Speed / 50, 0, 0);
        Playerpos = this.transform.position;
        if(Playerpos.x > 10)
        {
            this.transform.position = new Vector3(-10,0.2f,0);
        }
    }
}
