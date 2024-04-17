using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ScoreReset : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        ScoreManager.score_num = 0;
        ScoreManager.score_count = 0;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
