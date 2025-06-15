using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.UI;

public enum Recursos
{
    Quadrado,
    Circulo,
    Triangulo,
    Losango,
    Estrela
}

public class RecursosController : MonoBehaviour
{
    [SerializeField] private List<GameObject> _prefabRecursos;
    [SerializeField] private List<RectTransform> _slotsRecursos;

    private List<int> _recursosDisponiveis;

    // Start is called before the first frame update
    void Start()
    {
        transform.SetAsLastSibling();

        _recursosDisponiveis = Enum.GetValues(typeof(Recursos)).Cast<int>().ToList();

        foreach(int val in _recursosDisponiveis)
        {
            GameObject recurso = Instantiate(_prefabRecursos[val], _slotsRecursos[val]);
            recurso.GetComponent<Image>().color = Color.black;
        }
    }

    public bool EstaDisponivel(int val)
    {
        return _recursosDisponiveis.Contains(val);
    }

    public void RecursoDado(int val)
    {
        _recursosDisponiveis.Remove(val);
    }

    public void RecursoLiberado(int val)
    {
        GameObject recurso = Instantiate(_prefabRecursos[val], _slotsRecursos[val]);
        recurso.GetComponent<Image>().color = Color.black;

        _recursosDisponiveis.Add(val);
    }
}
