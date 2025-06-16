using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class AvancarFase : MonoBehaviour
{
    [SerializeField] private GameObject _mensagemFaseConcluida;

    private List<ThreadController> _controladoresDeThreads;

    private void Start()
    {
        GameObject[] aux = GameObject.FindGameObjectsWithTag("Thread");

        _controladoresDeThreads = new List<ThreadController>();
        foreach (GameObject thread in aux)
        {
            _controladoresDeThreads.Add(thread.GetComponent<ThreadController>());
        }
    }

    private void Update()
    {
        for(int i = 0; i < _controladoresDeThreads.Count; i++)
        {
            if(_controladoresDeThreads[i] == null)
            {
                _controladoresDeThreads.Remove(_controladoresDeThreads[i]);
                i--;
            }
        }
        if(_controladoresDeThreads.Count == 0)
        {
            _mensagemFaseConcluida.SetActive(true);
        }
    }

    public void Avancar()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);
    }
}
