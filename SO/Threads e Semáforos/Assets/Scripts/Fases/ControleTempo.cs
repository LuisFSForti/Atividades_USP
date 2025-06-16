using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ControleTempo : MonoBehaviour
{
    [SerializeField] bool pausarTempoVisible, pausarTempoInvisible;

    private void Awake()
    {
        Time.timeScale = 0f;
    }

    private void OnEnable()
    {
        Time.timeScale = pausarTempoVisible ? 0f : 1f;
    }

    private void OnDisable()
    {
        Time.timeScale = pausarTempoInvisible ? 0f : 1f;
    }
}
