using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TitleBackGround : MonoBehaviour
{
    public GameObject backgroundPrefab;
    GameObject bg1;
    GameObject bg2;



    Vector3 pos = new Vector3(52f, 0f, 0f);
    float speed = -0.25f;



    void Start()
    {
        bg1 = Instantiate(backgroundPrefab, new Vector3(0f, 0f, 0f), Quaternion.identity);
        bg2 = Instantiate(backgroundPrefab, pos, Quaternion.identity);
    }



    void FixedUpdate()
    {
        bg1.transform.Translate(speed, 0, 0);
        bg2.transform.Translate(speed, 0, 0);



        if (bg1.transform.position.xÅ@<= -52f)
        {
            Destroy(bg1);
            bg1 = Instantiate(backgroundPrefab, pos, Quaternion.identity);
        }
        if (bg2.transform.position.x <= -52f)
        {
            Destroy(bg2);
            bg2 = Instantiate(backgroundPrefab, pos, Quaternion.identity);
        }
    }
}
